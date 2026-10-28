#include <stdio.h>

int sum(int n);

int main(void)
{
	int s;

	s = sum(10);		// 1부터 10까지의 합
	printf("%d\n", s);

	return 0;
}
