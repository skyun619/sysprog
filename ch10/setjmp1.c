#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;	// jump buffer
void foo(void), bar(void);

int main()
{
    if (setjmp(buf)!=0) {
        printf("return from long jump\n");
        return 0;
    }
    printf("return from setjmp\n");

    foo();
    printf("return from foo\n");
    return 0;
}

/* Deeply nested function foo */
void foo(void)
{
    bar();
}

void bar(void)
{
    longjmp(buf, 1);	// setjmp함수 리턴 위치로 점프
}		// 둘째 인수는 nonzero 사용
