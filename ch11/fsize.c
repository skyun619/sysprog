#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
    int fd;
    char buf[BUFSIZE];
    ssize_t nbyte;
    long size;

    fd = 0;     // standard input
    if (argc > 1) {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0) { perror("open"); exit(1); }
    }
    size = 0;
    while ( nbyte = read(fd, buf, BUFSIZE), nbyte > 0) {
        size += nbyte;
	printf("nbyte = %ld\n", nbyte);
    }
    close(fd);
    printf("size : %ld byte\n", size);
    return 0;
}

