CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_handler signal_segfault signal_alarm signal_sigaction recv_signal send_signal

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o

signal_sigaction: signal_sigaction.o
	$(CC) -o signal_sigaction signal_sigaction.o

recv_signal: recv_signal.o
	$(CC) -o recv_signal recv_signal.o

send_signal: send_signal.o
	$(CC) -o send_signal send_signal.o

clean:
	rm -f *.o signal_handler signal_segfault signal_alarm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<