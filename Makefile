CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_handler signal_segfault signal_alarm

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o

clean:
	rm -f *.o signal_handler signal_segfault signal_alarm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<