#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buf[BUFSIZE];
    ssize_t nbyte;
    long size;

    fd1 = 0;        // standard input
    fd2 = 1;        // standard output
    if (argc > 1) {
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 < 0) { perror("open read"); exit(1); }
    }
    if (argc > 2) {
        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd2 < 0) { perror("open write"); exit(1); }
    }
    size = 0;
    while ( nbyte = read(fd1, buf, BUFSIZE), nbyte > 0)
        write(fd2, buf, nbyte);
    return 0;
}

