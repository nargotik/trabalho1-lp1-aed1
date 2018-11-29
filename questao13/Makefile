CC=gcc
CFLAGS=-I.
# Define as dependencias
DEPS = $(wildcard *.h)
# Define os ficheiros c a incluir excluindo o programa sensor
OBJ = $(filter-out main-sensor.c,$(wildcard *.c))
# Define os ficheiros c a incluir no programa sensor
OBJSENSOR = $(filter-out main.c,$(wildcard *.c))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	$(CC) -o ../bin/$(shell basename $(CURDIR))-main $(OBJ) $(CFLAGS)
	$(CC) -o ../bin/$(shell basename $(CURDIR))-sensor $(OBJSENSOR) $(CFLAGS)
clean:
	rm bin/build
