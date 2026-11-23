#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;

    /* Open an existing file for reading */
    fd = open("foo1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("fd = %d\n", fd);		// fd는 3
    close(fd);
    return 0;
}
