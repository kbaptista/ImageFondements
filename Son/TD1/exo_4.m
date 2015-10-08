function [] = exo_4()

freq=440;

amp = 1.0;
phi = 0.0;
Fech = 44100;
N = Fech*2; % n*Fech = n secondes 

snr=[];
for bits = 8:16 % Nombre de bits de quantification
nbval = 2^(bits-1); 

tab_1=syn_sinus(freq, amp, phi, Fech, N);
bruit=(round(tab_1*nbval)/nbval)-tab_1;

rms_bruit=sqrt(sum(bruit.^2));
rms_signal=sqrt(sum(tab_1.^2));
snr=[snr 20.0*log10(rms_signal/rms_bruit)];

end

plot(8:16, snr);

end