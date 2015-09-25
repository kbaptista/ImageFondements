CC = gcc
CCFLAGS = -Wall -std=c99
LIBS = -lglut -lGLU -lgsl -lgslcblas -lm -lGL

TARGET= quaternion/point.o quaternion/vector3d.o quaternion/quaternion.o

PROG = exo1-1 exo2-1 exo3-1

all : $(TARGET) $(PROG)
	cd .

% :
	$(CC) $(CCFLAGS) $(TARGET) $@.c -o $@ $(LIBS)

clean:
	rm -rf $(TARGET) $(PROG) *.o *~
