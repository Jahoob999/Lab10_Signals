/**
 * File: signal_sigaction.c
 * Modified by: Jacob Newberry
 * 
 * Brief summary of program:
 * This program waits for the SIGUSR1 signal and handles it using sigaction.
 * when the signal is recieved it prints a message indicating that process has
 * received the signal.
 * To send SIGUSR1 to this process in another terminal use the command:
 * kill -SIGUSR1 <pid>
 * replace <pid> with the process ID of the program, which is printed out when
 * when the program starts.
 */

 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <unistd.h>
 
 void handle_sigusr1()
 {
    int pid = getpid();
    printf("Process %d received SIGUSR1\n", pid);
 }

 int main(void)
 {
    int pid = getpid();
    printf("Process %d is waiting for SIGUSR1 signal\n", pid);

    struct sigaction sa = {0};
    sa.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    
    while (1)
    {
        //loops infinitely waiting for SIGUSR1 signal
    }

    return 0;
 }

