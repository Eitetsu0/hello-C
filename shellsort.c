#include <stdio.h>

void shellsort(int v[],int n);
void pi(int i[],int n);

int main()
{
	int v[]={5,4,3,2,1,7,8,6,9,0};
	pi(v,10);
	shellsort(v,10);
	pi(v,10);

	return 0;
}

//sort v[] into increasing order
void shellsort(int v[],int n)
{
	int gap,i,j,temp;

	for(gap=n/2;gap>0;gap/=2)
		for(i=gap;i<n;i++)
			for(j=i-gap;j>=0 && v[j]>v[j+gap];j-=gap){
				temp=v[j];
				v[j]=v[j+gap];
				v[j+gap]=temp;
			}
}

void pi(int i[],int n)
{
	int j;
	for(j=0;j<n;j++)
		printf(" %d",i[j]);
	printf("\n");
}
