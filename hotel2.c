/* n男m女 k对情侣
 * 双人间a元
 * 三人间b元
 * 情侣间c元
 *
 * 输入格式：
 * m n k a b c
 * 0<=m,n,k<=1e3
 * 0<=a,b,c<=1e9
 */

#include <stdio.h>

int main()
{

	unsigned int m,n,k,a,b,c;
	unsigned int nrecs,s,min;

	scanf("%u",&nrecs);
	while(nrecs--){
		scanf("%u%u%u%u%u%u",&m,&n,&k,&a,&b,&c);
		min=~0;

		for(unsigned int i=0;i<=k;i++){
			unsigned int ks=i*c;
			unsigned int mmin,nmin;
			mmin=nmin=~0;

			for(unsigned int j=0;j<=m+k-i+2;j+=3){
				s=j/3*b+(j<m+k-i?((m+k-i-j)%2?(m+k-i-j)/2+1:(m+k-i-j)/2):0)*a;
				mmin=mmin<s?mmin:s;
				if(j>0&&j<(m+k-i)/3*3)
					j=(m+k-i)/3*3;
			}
			for(unsigned int j=0;j<=n+k-i+2;j+=3){
				s=j/3*b+(j<n+k-i?((n+k-i-j)%2?(n+k-i-j)/2+1:(n+k-i-j)/2):0)*a;
				nmin=nmin<s?nmin:s;
				if(j>0&&j<(n+k-i)/3*3)
					j=(n+k-i)/3*3;
			}
			s=ks+mmin+nmin;
			min= min<s?min:s;
			if(i>=2&&i<k-1)
				i=k-1;
		}
		printf("%u\n",min);
	}
	return 0;
}
