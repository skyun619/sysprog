#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct stat fstat;
    int mode;
    char *ftype, *readok;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    if (stat(argv[1], &fstat) < 0) { perror("stat"); exit(2); }

    printf("file size = %ld bytes\n", fstat.st_size);
    mode = fstat.st_mode;
    if (S_ISREG(mode)) ftype = "regular";
    else if (S_ISDIR(mode)) ftype = "directory";
    else ftype = "others";

    if (mode & S_IRUSR) readok = "yes";
    else readok = "no";
    printf("file type : %s\nread : %s\n", ftype, readok);

    return 0;
}

