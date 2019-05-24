CC=gcc
CFLAGS=-O3 -g3  -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -Wno-format-security -Wno-unused-but-set-variable -Wno-unused-result -std=c99
# Define as dependencias
DEPS = $(wildcard *.h)
# Define os ficheiros c a incluir excluindo o programa sensor
	OBJ = $(filter-out main-sensor.c main-demodata.c,$(wildcard *.c))
# Define os ficheiros c a incluir no programa sensor
OBJSENSOR = $(filter-out main.c main-demodata.c,$(wildcard *.c))
# Define os ficheiros c a incluir no programa sensor TCPSERVER
OBJSENSORTCP = $(filter-out main.c main-sensor.c,$(wildcard *.c))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	$(CC) -o ../bin/$(shell basename $(CURDIR))-main $(OBJ) $(CFLAGS)
	$(CC) -o ../bin/$(shell basename $(CURDIR))-sensor $(OBJSENSOR) $(CFLAGS)
	$(CC) -o ../bin/$(shell basename $(CURDIR))-demodata $(OBJSENSORTCP) $(CFLAGS)
clean:
	rm bin/build
