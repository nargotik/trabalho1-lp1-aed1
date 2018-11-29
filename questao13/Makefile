CC=gcc
CFLAGS=-I.
# Define as dependencias
DEPS = $(wildcard *.h)
# Define os ficheiros c a incluir
OBJ = $(wildcard *.c)


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	$(CC) -o ../bin/$(shell basename $(CURDIR)) main.c $(CFLAGS)
	$(CC) -o ../bin/$(shell basename $(CURDIR))-sensor sensor.c $(CFLAGS)
clean:
	rm bin/build
