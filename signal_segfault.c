/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Jacob Newberry
 * 
 * Brief summary of modifications:
 * First made a signal handler for SIGSEGV that would print an error message
 * and return to the main function
 * Because this caused an infinite loop, added exit(1) to the signal handler
 * so the program would exit after segmentation fault was handled.
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler() 
{
    printf("Segmentation fault from dereferencing a null pointer\n");
    exit(1);
}

int main (int argc, char* argv[]) {

    //register the signal handler for SIGSEGV
    signal(SIGSEGV, signal_handler);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}