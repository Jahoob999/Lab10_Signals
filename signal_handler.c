/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Jacob Newberry
 * 
 * Brief summary of modifications:
 * when SIGINT is recieved the program no longer exits
 * program will automatically stop after 10 seconds instead of looping 
 * infinitely 
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * @brief Signal handler for SIGINT - prints a message and
 */
void handle_signal() {
    printf("Received a signal\n");
}

int main() {

    int pid = fork();
    if (pid == 0) //child process
    {
        // Register for the signal
        signal(SIGINT, handle_signal);
        
        // While loop to show program is still running
        while(1) 
        {
            printf("Sleeping\n");
            sleep(1);
        }
    }
    else //parent process
    {
        //ignores SIGINT in the parent process so it is not handled twice
        signal(SIGINT, SIG_IGN);
        //waits 10 seconds before killing child process
        //This is inside a for loop because a SIGINT would skip the sleep
        sleep(10);
        kill(pid, SIGKILL);
    }
    wait(NULL);

    return 0;
}