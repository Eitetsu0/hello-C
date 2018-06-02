#include <stdio.h>

int main()
{
	for(int i=32;i<127;++i)
		printf("%c%c", i, (i+1)%8?' ':'\n');
	return 0;
}
