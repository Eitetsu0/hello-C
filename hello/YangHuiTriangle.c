#include <stdio.h>

#define EOL -1
#define MAXLINE 100

#define swap(a,b) {int *temp=a; a=b;b=temp;}

void calnext(int *ol,int *nl);

int main()
{
	int s[MAXLINE*2]={1,EOL};
	int *a=s,*b=s+MAXLINE;
	*b=1;
	int i,j;

	i=12;

	for(;i>=0;i--){
		//print spaces
		printf("%s",i%2?"   ":"");
		for(j=i/2-1;j>=0;j--)
			printf("      ");
		//print the val of a
		for(j=0;*(a+j)!=EOL;j++)
			printf("%5d ",*(a+j));

		printf("\n");
		swap(a,b);
		calnext(b,a);
	}
	return 0;
}
void calnext(int *ol,int *nl)
{
	*nl++=1;
	while(*++ol!=EOL)
		*nl++ = *(ol-1) + *ol;
	*nl++=1;
	*nl=EOL;
}
