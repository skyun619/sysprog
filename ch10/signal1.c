#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

void sigint_handler(int sig) /* SIGINT handler */
{
    printf("Ctrl-C is pressed!\n");
    fflush(stdout);
    sleep(5);
    printf("Bye signal handler\n");
    exit(1);
}

int main(int argc, char** argv)
{
    /* Install the SIGINT handler */
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
 	fprintf(stderr, "signal error\n");
        exit(1);
    }
    /* Wait for the receipt of a signal */
    pause();
    printf("Bye main\n");
    return 0;
}
