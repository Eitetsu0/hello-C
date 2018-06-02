#include <stdio.h>
#define EF 3.5
#define s(x) EF*x*x

int main()
{
	int a=0,b=0,c=0,d=1,e=0,f=0,g=0b1,h=0,i=0,n=0;

	scanf("%d",&a);
	while(a>0){
		putchar(a%10+'0');
		a/=10;
	}

	return 0;
}
/*
int s[1000000]={0};
for(int i=0;i<1000000;i++)
	s[a[i]]++;
for(int i=0;i<1000000;i++)
	if(s[i]>0)
		printf("%d ",i);
*/
