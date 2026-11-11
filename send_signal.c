/**
 * File: send_signal.c
 * Modified by: Jacob Newberry
 * 
 * Brief summary of program:
 * sends a SIGUSR1 signal to the process ID provided as a command line 
 * argument along with a randomly generated integer. Program also prints
 * the value sent and the process ID of the receiver to verify that the
 * signal was sent and received correctly.
 */

 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <time.h>

 int main(int argc, char *argv[])
{
    //seeds the random number generator
    srand(time(NULL));
    if (argc == 2)
    {
        int pid = atoi(argv[1]);
        union sigval value;
        value.sival_int = rand(); // Example value to send with the signal

        if (sigqueue(pid, SIGUSR1, value) == -1)
        {
            perror("sigqueue failed");
            exit(1);
        }
        else
        {
            printf("Sent SIGUSR1 signal to process %d with value %d\n", pid, value.sival_int);
        }
    }
    else
    {
        printf("Please provide a process ID to send the signal to.\n");
    }
}
