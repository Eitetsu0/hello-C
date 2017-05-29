#include <stdio.h>

int main()
{
	int c;
	while ((c = getchar())!= EOF && c>='a' && c<='z') {
		putchar((c+3-'a')%26+'a');
	
	}
	return 0;
}
