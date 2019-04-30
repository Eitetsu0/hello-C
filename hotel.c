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

#define rooms2(n) (((n)%(2))?((n+1)/2):((n)/2))
#define rooms3sum(n,pricea,priceb) (((n)%(3))?((n)/3*priceb+((pricea<priceb)?pricea:priceb)):((n)/3*priceb))

int main()
{
	unsigned int m,n,k,a,b,c;
	unsigned int recs,s,min;

	scanf("%u",&recs);
	while(recs--){
		scanf("%u%u%u%u%u%u",&m,&n,&k,&a,&b,&c);
		if(c<=a && c*3<=b*2){ //情侣房间价最低
			s=k*c;
			if(a*3<=b*2){ //双人间比3人间低
				min=s+(rooms2(n)+rooms2(m))*a;
			}else {
				min=s+rooms3sum(n,a,b)+rooms3sum(m,a,b);
			}
		}else if(a*3<=b*2){ //双人间价格最低
//			if(c<2*a){
				min=(rooms2(n+k)+rooms2(m+k))*a;
				s=c+(rooms2(n+k-1)+rooms2(m+k-1))*a;
				min= min<s?min:s;
//			}else
//				min=(rooms2(n+k)+rooms2(m+k))*a;
		}else {
			min=rooms3sum(n+k,a,b)+rooms3sum(m+k,a,b);
			s=c+rooms3sum(n+k-1,a,b)+rooms3sum(m+k-1,a,b);
			min= min<s?min:s;
			s=c+c+rooms3sum(n+k-2,a,b)+rooms3sum(m+k-2,a,b);
			min= min<s?min:s;
		}
		printf("%u\n",min);
	}

	return 0;
}
