CC = gcc
CCFLAGS = -Wall -std=c99
LIBS =  -lm -lGL -lglut -lGLU -ltiff -lgsl -lgslcblas -lGLEW 

TARGET= exo1-1-tableaux-vertex gsl_matrix

all : $(TARGET)
	cd .

% :  %.c
	$(CC) $(CCFLAGS) $@.c -o $@ $(LIBS)

clean:
	rm -rf $(TARGET) *.o *~

