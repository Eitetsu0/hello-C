#include <stdio.h>
#define N ~0

int main()
{
	int i=N;
	long li=N;
	short si=N;
	char c=N;
	int n=1;
	while((i*=2)!=0)
		n++;
	printf("len of int is %d \n",n);
	n=1;
	while((li<<=1)!=0)
		n++;
	printf("len of long int is %d \n",n);
	n=1;
	while((si<<=1)!=0)
		n++;
	printf("len of short int is %d \n",n);
	n=1;
	while((c<<=1)!=0)
		n++;
	printf("len of char is %d \n",n);
	return 0;
}
