# Signals Lab
This repository contains various programs working with different signals including
- signal_handler
- signal_alarm
- signal_segfault
- signal_sigaction
- recv_signal and send_signal

## signal_handler
This program sets a signal handler for a SIGINT like CTRL+C and when it recieves that signal prints a message acknowledging that signal. When the program starts up starts a loop that takes ten seconds while waiting for the SIGINT. After ten seconds the program will close

## signal_alarm
This program sets a signal handler for SIGALRM. When the program starts it sets a 5 second alarm and then enters an infinite loop waiting for the alarm to go off. When the alarm goes off a message is printed acknowledging the signal and the program closes.

## signal_segfault
This program sets a signal handler for SIGSEGV. When the program starts it sets a pointer equal to NULL it then tries derefrencing that pointer which causes a segmentation fault. The segmentation fault is handled by printing a message explaining the seg fault and then closes the program.

## signal_sigaction
This program waits for the SIGUSR1 signal and handles it using sigaction.
when the signal is recieved it prints a message indicating that process has received the signal. To send SIGUSR1 to this process in another terminal use the command: kill -SIGUSR1 `<pid>` replace `<pid>` with the process ID of the program, which is printed out when the program starts.

## recv_signal and send_signal
recv_signal also handles SIGUSR1, but in a different way. It waits for SIGUSR1 from a different program send_signal and when it receives the signal it prints the number sent with the signal and also the pid of the process the signal was sent from. send_signal is responsible for sending the signal. This program should be prompted with the process ID of recv_signal (which is printed when recv_signal starts) in the command line. send_signal then generates a number using rand() and sends a SIGUSR1 signal to recv_signal with the number using sigqueue().