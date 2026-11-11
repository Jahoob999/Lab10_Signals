/**
 * File: signal_alarm.c
 * Modified by: Jacob Newberry
 * 
 * Brief summary of program:
 * Program sets a 5 second alarm and waits for the signal to be received.
 * When the signal is received the program prints a message acknowledging
 * the signal and then exits.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <unistd.h>

 void signal_alarm()
 {
    printf("Alarm signal received\n");
    exit(0);
 }
 int main(void) 
 {
    // register the signal handler for SIGALRM
    signal(SIGALRM, signal_alarm);

    printf("Setting an alarm for 5 seconds\n");
    //sets 5 second alarm
    alarm(5);
    //infinite loop to show program is still running while waiting for 
    //the alarm signal
    while(1) 
    {
        printf("waiting\n");
        sleep(1);
    }
    return 0;
 }
