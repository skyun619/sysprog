#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd, fd2;

    /* Open an existing file for reading */
    fd = open("foo1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("fd = %d\n", fd);		// fd는 3
    close(fd);

    fd2 = open("foo1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("fd2 = %d\n", fd2);		// fd는 3
    close(fd2);
    return 0;
}
