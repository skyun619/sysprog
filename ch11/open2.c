#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;

    /* Create a new file for writing */
    fd1 = open("foo2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd1 < 0) {
        perror("write open");
        exit(1);
    }
    printf("write fd = %d\n", fd1);

    /* Open an existing file for reading */
    if ( (fd2 = open("foo2.txt", O_RDONLY)) < 0) {
        perror("read open");
        exit(1);
    }
    printf("read fd = %d\n", fd2);

    exit(0);
}

