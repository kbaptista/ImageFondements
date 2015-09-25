CC = gcc
CCFLAGS = -Wall -std=c99
LIBS = -lm

TARGET = point.o vector3d.o quaternion.o

all : $(TARGET)

%.o : %.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@
	
clean :
	rm -f *~ *.o
