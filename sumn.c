#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t n=0;
	uint32_t s=0;

	uint32_t mult(uint16_t a , uint16_t b);

	scanf("%hu",&n);  // h for short
	s=mult(1+n,n);
	s>>=1;
	printf("s=%u\n",s);

	return 0;
}

uint32_t mult(uint16_t a , uint16_t b)
{
	uint16_t mask[16]={01,02,04,010,020,040,0100,0200,0400,01000,02000,04000,010000,020000,040000,0100000};

	uint32_t m=0;

	for(int i=0;i<16;i++)
		mask[i]&a && (m+=b<<i);

	return m;
}
