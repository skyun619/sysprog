#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	FILE *fp;

	fp = stdout; // standard output
	if (argc > 1) {
		fp = fopen(argv[1], "w");
		if (fp==NULL) { perror("fopen"); exit(1); }
	}
	while ( fgets(buf, BUFSIZE, stdin) != NULL)
	fputs(buf, fp);
	return 0;
}
