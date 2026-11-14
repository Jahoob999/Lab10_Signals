/**
 * File: recv_signal.c
 * Modified by: Jacob Newberry
 * 
 * Brief summary of program:
 * waits for a SIGUSR1 signal to be send from send_signal.c and prints 
 * the value sent with the signal and the process ID of the sender
 */

 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <unistd.h>
 
 void handle_sigusr1(int signal, siginfo_t *siginfo, void *notused)
 {
   printf("Recieved value %d from process %d\n", 
      siginfo->si_value.sival_int, siginfo->si_pid);
   exit(0);
 }

 int main(void)
 {
    int pid = getpid();
    printf("Process %d is waiting for SIGUSR1 signal\n", pid);

    struct sigaction sa = {0};
    sa.sa_sigaction = &handle_sigusr1;
    //SA_SIGINFO flag is set to allow the signal handler to recieve
    //additional information about the signal
    sa.sa_flags = SA_SIGINFO; 
    sigaction(SIGUSR1, &sa, NULL);
    
    while (1)
    {
        //loops infinitely waiting for SIGUSR1 signal
    }

    return 0;
 }