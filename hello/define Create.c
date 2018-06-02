#include <stdio.h>

#define Create(t,a,b)  t a ## b
#define dprint(s,n) printf( "=%d",s##n)

int main()
{
    int i=0;
//	for ( i = 0; i < 10; i++)
	{
		Create(int, test, i) = i;
		dprint(test, i);
		i++;
		Create(int, test, i) = i;
		dprint(test, i);
	}
	return 0;
}
