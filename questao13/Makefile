CC=gcc
CFLAGS=-I.
# Define as dependencias
DEPS = $(wildcard *.h)
# Define os ficheiros c a incluir
OBJ = $(filter-out main-sensor.c,$(wildcard *.c))
OBJSENSOR = $(filter-out main.c,$(wildcard *.c))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	$(CC) -o ../bin/$(shell basename $(CURDIR)) ($OBJ) $(CFLAGS)
	$(CC) -o ../bin/$(shell basename $(CURDIR))-sensor ($OBJSENSOR) $(CFLAGS)
clean:
	rm bin/build
