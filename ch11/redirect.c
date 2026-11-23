#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) { perror("open"); exit(1); }
	dup2(fd, 2); // stderr redirection
	close(fd);
	printf("Hello standard output\n"); // 파일에 저장됨
	fprintf(stderr, "Hello standard error output\n");
	return 0;
}

