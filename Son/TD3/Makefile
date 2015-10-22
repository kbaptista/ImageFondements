CFLAGS = -c 
TARGET = gnuplot_i.o son.o son

# Makefile

all: $(TARGET)

son: gnuplot_i.o son.o
	gcc son.o gnuplot_i.o -o son -L/usr/lib -lfftw3 -lm

son.o: son.c 
	gcc -I/usr/include -c son.c -o son.o

gnuplot_i.o: gnuplot_i.c
	gcc $(CFLAGS) gnuplot_i.c

clean:
	rm -f *.o *~ 
	rm $(TARGET)