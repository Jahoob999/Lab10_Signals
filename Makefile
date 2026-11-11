CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_handler signal_segfault

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

clean:
	rm -f *.o signal_handler signal_segfault

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<