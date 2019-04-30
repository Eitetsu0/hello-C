//count prime numbers from 500 to 1000

#include <stdio.h>

int main()
{
	int c=0;

	for(int n=501;n<1000;n++)
		for(int i=2;;i++) //素数判断
			if(n%i==0) //不能正确判断2
				break;
			else if(i>=n/2){ //过半不能整除就可以认为是素数
				c++;
				break;
			}
	printf("c=%d\n",c);

	return 0;
}
