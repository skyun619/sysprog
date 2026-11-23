#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <error.h>

struct sigaction newact, oldact;

void sigint_handler(int sig) /* SIGINT handler */
{
    printf("Received signal = %d\n", sig);
    sleep(3);
    sigaction(SIGINT, &oldact, NULL);
}

int main(int argc, char** argv)
{
    /* Install the SIGINT handler */
    newact.sa_handler = sigint_handler;
    if (sigaction(SIGINT, &newact, &oldact) != 0) {
        fprintf(stderr, "sigact error\n");
        exit(1);
    }

    /* Wait for the receipt of a signal */
    printf("Press Ctrl-C two times\n");
    while (1)
    {
        sleep (1);
    }
    printf("Bye main\n");
    return 0;
}
