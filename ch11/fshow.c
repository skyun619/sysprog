#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	FILE *fp;

	fp = stdin; // standard input
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (fp==NULL) { perror("fopen"); exit(1); }
	}
	while ( fgets(buf, BUFSIZE, fp) != NULL)
	fputs(buf, stdout);
	return 0;
}
