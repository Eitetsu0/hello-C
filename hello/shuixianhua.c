#include <stdio.h>

int main()
{
	int s=0;
	for(int i=1;i<=9;++i)
	{
		for(int j=0;j<=9;++j)
		{
			for(int k=0;k<=9;++k)
			{
				if((s=i*100+j*10+k)==i*i*i+j*j*j+k*k*k)
					printf("%d\n",s);
			}
		}
	}
	return 0;
}
