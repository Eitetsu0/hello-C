#include <stdio.h>

int bar(int c,int d)
{
	int e=c+d;
	return e;
}

int foo();
int main(void)
{
	struct {
		char a;
		short b;
		int c;
		char d;
	} s;

	s.a = 1;
	s.b = 2;
	s.c = 3;
	s.d = 4;
	printf("%lu\n", sizeof(s));

	foo(2,3,4);
	return 0;
}

int foo(int a,int b)
{
	return bar(a, b);
}
