#include <stdio.h>

int main()
{
	int v[]={5,6,4,1,2,3,7,8,9,0};
	void pi(int i[],int n);
	void qsort(int v[], int left ,int right);
	void rqsort(int *v, int len);

	pi(v,10);
	qsort(v,0,9);
	pi(v,10);
	rqsort(v,10);
	pi(v,10);

	return 0;
}
void swap(int v[], int i ,int j);
//qsort:sort v[left] ... v[right] into increasing order
void qsort(int v[], int left ,int right)
{
	int i,last;

	if(left >= right)	//do nothing if array contains fewer than two elements
		return;
	//swap(v,left,(left+right)/2);//move partition elem to v[0]
	last = left;
	for(i=left+1;i<=right;i++)//partition
		if(v[i]<v[left])
			swap(v,++last,i);
	swap(v,left,last);//restore partition elem
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}
//rqsort:sort v[left] ... v[right] into decreasing order
void rqsort(int *v, int len)
{
	int i,*last;
	//void swap(int v[], int i ,int j);

	if(len<2)	//do nothing if array contains fewer than two elements
		return;
	//swap(v,left,(left+right)/2);//move partition elem to v[0]
	last = v;
	for(i=0;i<len;i++)//partition
		if(v[i]>*v)
			swap(v,++last-v,i);
	i=last-v;
	swap(v,0,i);//restore partition elem
	rqsort(v,i);
	rqsort(last+1,len-i-1);
}
//swap:interchange v[i] and v[j]
void swap(int v[],int i,int j)
{
	int temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
//pi:print i[0] ... i[n-1]
void pi(int i[],int n)
{
	int j;
	for(j=0;j<n;j++)
		printf(" %d",i[j]);
	printf("\n");
}
