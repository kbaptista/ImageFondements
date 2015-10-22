#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <complex.h>
#include "gnuplot_i.h"
#include <complex.h>
#include "math.h"
#include <fftw3.h>

#define SAMPLING_RATE 44100.0
#define CHANNELS_NUMBER 1
#define N 4410
#define TIME 36
#define real double

static fftw_plan plan;


fftw_complex data_in[N];
fftw_complex data_out[N];

typedef real frame[N];
typedef complex spectrum[N];

/* input */

static char *SOUND_FILE_NAME_READ = "tmp-in.raw";
static real cache_in[N/2];

static gnuplot_ctrl *h = NULL;

FILE *
sound_file_open_read (char *sound_file_name)
{
#define MAX_CMD 256
  char cmd[MAX_CMD];

  assert (sound_file_name);

  snprintf (cmd, MAX_CMD,
	    "sox %s -c %d -r %d -e signed-integer -b 16 %s",
	    sound_file_name,
	    CHANNELS_NUMBER, (int)SAMPLING_RATE, SOUND_FILE_NAME_READ);

  system (cmd);

  bzero (cache_in, N/2*sizeof(real));

  return fopen (SOUND_FILE_NAME_READ, "rb");
}

void
sound_file_close_read (FILE *fp)
{
  assert (fp);

  fclose (fp);

  
  unlink (SOUND_FILE_NAME_READ);
}

int
sound_file_read (FILE *fp, frame s)
{
  int result;

  int i;

  static short tmp[N/2*CHANNELS_NUMBER];

  assert (fp && s);

  for (i=0; i<N/2; i++)
    {
      s[i] = cache_in[i];
    }

  bzero (tmp, N/2*CHANNELS_NUMBER*sizeof(short));
  result = fread (tmp, sizeof(short), N/2*CHANNELS_NUMBER, fp);

  for (i=0; i<N/2; i++)
    {
      cache_in[i] = s[N/2+i] = tmp[i*CHANNELS_NUMBER] / 32768.0;
    }

  return (result == N/2);
}

/* output */

static char *SOUND_FILE_NAME_WRITE = "tmp-out.raw";
static char *sound_file_name_write = "out.wav";

static real cache_out[N/2];

FILE *
sound_file_open_write (void)
{
  bzero (cache_out, N/2*sizeof(real));

  return fopen (SOUND_FILE_NAME_WRITE, "wb");
}

void
sound_file_close_write (FILE *fp)
{
#define MAX_CMD 256
  char cmd[MAX_CMD];

  assert (fp);

  fclose (fp);

  snprintf (cmd, MAX_CMD,
      "sox -c %d -r %d  -e signed-integer -b 16 %s %s",
      CHANNELS_NUMBER, (int)SAMPLING_RATE, SOUND_FILE_NAME_WRITE,
      sound_file_name_write);

  system (cmd);

  unlink (SOUND_FILE_NAME_WRITE);
}

void
sound_file_write (frame s, FILE *fp)
{
  int i;

  static short tmp[N/2*CHANNELS_NUMBER];

  assert (fp && s);

  for (i=0; i<N/2; i++)
    {
      real v = s[i] + cache_out[i];
      short _s = (v < -1) ? -32768 : (v > 1) ? 32767 : (short) (v * 32767);

      cache_out[i] = s[N/2+i];

      int channel;

      for (channel=0; channel<CHANNELS_NUMBER; channel++)
  {
    tmp[i*CHANNELS_NUMBER+channel] = _s;
  }
    }

  fwrite (tmp, sizeof(short), N/2*CHANNELS_NUMBER, fp);
}

void
plot_init(){
  h = gnuplot_init ();
  gnuplot_setstyle (h, "lines");
}

void
plot_temporal(frame x_axis, frame s){
  gnuplot_resetplot(h);
  gnuplot_plot_xy (h, x_axis, s, N, "Son-Temporel");
  
}

void
plot_spec(frame freq, frame amplitude){
  gnuplot_resetplot(h);
  gnuplot_plot_xy (h, freq, amplitude, N, "Son-Spectral");
  //sleep(1);
  
}

void dft (double s[N], complex S[N]){
  int m;
  for (m = 0; m < N; ++m)
  {
    S[m]=0.0;
  }
  for (m = 0; m < N; ++m)
  {
    int n;
    for (n = 0; n < N; ++n)
    {
      /* code */
      S[m]+=s[n]*cexp(-1.0*I*2*M_PI*n*m/N);
    }
  }
}

void 
cartesian_to_polar (complex S[N], double amp[N], double phs[N]){
  int i;
  for (i = 0; i < N; ++i)
  {
    amp[i]=cabs(S[i]);
    phs[i]=carg(S[i]);
  }
}

void 
fft_init(){

  plan = fftw_plan_dft_1d(N, data_in, data_out, FFTW_FORWARD, FFTW_ESTIMATE);
}

void
fft()
{
  fftw_execute (plan);
}


void
fft_exit(){
  fftw_destroy_plan (plan);
}

void
get_max_freqs(double * son, double * amp_res, double * freq_res)
{
  int i;
  for (i = 1; i < (N/2)-1; ++i)
  {
    if ((son[i-1]<= son[i])&&(son[i+1]<son[i]))
    {
      if (amp_res[1]<son[i])
      {
        if (amp_res[1]>amp_res[2])
        {
          amp_res[2]=son[i];
          freq_res[2]=(double)i*SAMPLING_RATE/N;
        }
        else
        {
          amp_res[1]=son[i];
          freq_res[1]=(double)i*SAMPLING_RATE/N;
        }      
      }
      else if (amp_res[2]<son[i])
      {
        amp_res[1]=son[i];
        freq_res[1]=(double)i*SAMPLING_RATE/N;
      }
    }
  }
  printf("%f, %f\n", freq_res[1], freq_res[2] );
}

int
main (int argc, char *argv[])
{

  /* plan necessaire à fast fourrier transform */

  FILE *input, *output;

  /* temporal */
  frame s;

  /* spectral */
  spectrum S;

  assert (sizeof(short) == 2);

  if (argc != 2)
    {
      fprintf (stderr, "usage: %s <soundfile>\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  /* init */
  fft_init ();

  input = sound_file_open_read (argv[1]);
  output = sound_file_open_write ();

  plot_init();

  frame x_axis_temp;

  int i;
  for (i = 0; i < N ; ++i)
  {
    x_axis_temp[i]=i/SAMPLING_RATE;
  }
  
  frame x_axis_spec;

  for (i = 0; i < N ; ++i)
  {
    x_axis_spec[i]=i*SAMPLING_RATE/(2*N);
  }

  fft_init(s);
  
  double amp_res [TIME];
  double freq_res [TIME];
  for (i = 0; i < TIME; ++i)
  {
    amp_res[i] = 0.0;
    freq_res[i] = 0.0;
  }

  int x=0;

  /* process */
  while (sound_file_read (input, s))
  {

    /* ANALYSIS *//*  Frequentiel */
    
    /*
    sound_file_write (s, output);
    plot_temporal( x_axis_temp, s);
    sleep(1);
    */


    /* ANALYSIS *//*  Spectrale - Discrete Fourrier Transform */
    
    /*
    sound_file_write (s, output);
    double amp[N];
    double phs[N];

    dft(s, S);
    cartesian_to_polar(S, amp, phs);

    plot_spec(x_axis_spec, amp);
    sleep(1);
    */

    /* ANALYSIS*//* Spectrale - Fast Fourrier Transform */
    
    
    sound_file_write (s, output);

    for (i=0; i<N; i++)
    {
      data_in[i] = s[i];
    }

    fft();  

    double amp[N];
    double phs [N];

    cartesian_to_polar(data_out,amp,phs);

    get_max_freqs(amp, amp_res+x, freq_res+x);
    x+=2.0;

  }
/*
  for (i = 0; i < TIME; ++i)
  {
    printf("%f\n", freq[i]);
  }

  /* exit */
  fft_exit();
  sound_file_close_write (output);
  sound_file_close_read (input);

  //fft_exit ();

  exit (EXIT_SUCCESS);

  return 0;
}
