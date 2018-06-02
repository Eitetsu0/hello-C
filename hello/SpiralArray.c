#include <stdio.h>

int m,n;
int loc(int i,int j);

int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	//printf("m=%d,n=%d\n",m,n);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			printf("%2d ",loc(i,j));
		printf("\n");
	}
	return 0;
}
//loc:return the value located on (i,j)[(1,1)~(m,n)] ,0 if error
int loc(int i,int j)
{
	int min(unsigned int n,...);
	int roll;
	if((roll=min(4,i,m-i+1,j,n-j+1)-1)<0)
		return 0;
	//getchar();printf("(%d,%d)roll=%d\n",i,j,roll);
	if(m<=n && (i<=j && j<=n-(m+1)/2 && i<=(m+1)/2 || i<=m+j-n && j>n-(m+1)/2) || m>n && ((i<=j || j>=n/2+1) && i<=m-(n+1)/2 || i<=m+j-n && i>m-(n+1)/2))
		return 2*roll*(m+n-2)-4*(roll-1)*roll + (j-roll-1) + (i-roll);
	else
		return 2*(roll+1)*(m+n-2)-4*(roll+1)*roll - (i-roll-2) - (j-roll-1);
}

#include <stdarg.h>
//min:return the minimum from a list ,n is the length of the list
int min(unsigned int n,...)
{
	int m,t;
	va_list vp;
	va_start(vp,n);
	m=va_arg(vp,int);
	while(--n)
		if((t=va_arg(vp,int))<m)
			m=t;
	va_end(vp);
	return m;
}
