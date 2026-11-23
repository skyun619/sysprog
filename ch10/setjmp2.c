#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;		// jump buffer

int error1 = 0;
int error2 = 0;

void foo(void);
void bar(void);

int main()
{
    switch(setjmp(buf)) {
    case 0: // from setjmp call
	printf("error1 = %d, error2 = %d\n", error1, error2);
        foo();		        break;
    case 1:
        printf("Detected an error1 condition in foo\n");
        break;
    case 2:
        printf("Detected an error2 condition in foo\n");
        break;
    default:
        printf("Unknown error condition in foo\n");
    }
    exit(0);
}

/* Deeply nested function foo */
void foo(void)
{
    if (error1)		
	longjmp(buf, 1);
    bar();
}

void bar(void)
{
    if (error2)		
        longjmp(buf, 2);
}

