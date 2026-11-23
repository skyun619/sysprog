#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;

    printf("argc = %d\n", argc);

    for (i=0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    printf("--- Environment Variables ---\n");
    for (i=0; envp[i] != NULL; i++)
        printf("envp[%d] = %s\n", i, envp[i]);

    printf("--- GetEnv ---\n");
    printf("%s = %s\n", "HOME", getenv("HOME"));

    return 0;
}

