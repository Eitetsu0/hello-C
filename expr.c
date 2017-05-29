#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100

#include <math.h>
#define SIN '1'
#define COS '2'
#define TAN '3'
#define EXP '4'
#define POW '5'

int getop(char *);

int main(int argc,char *argv[])
{
	int i;
	double v[MAXLEN];
	double *p=v;
	for(i=1;i<argc;i++){
		if(isdigit(*argv[i]))
			*p++ = atof(argv[i]);
		else {
			switch(getop(argv[i])){
			case '+':
				if(p-v<2) goto err1;
				p--;
				*(p-1) += *p;
				break;
			case '*':
				if(p-v<2) goto err1;
				p--;
				*(p-1) *= *p;
				break;
			case '-':
				if(p-v<2) goto err1;
				p--;
				*(p-1) -= *p;
				break;
			case '/':
				if(p-v<2) goto err1;
				if (*--p != 0.0)
					*(p-1) /= *p;
				else
					goto err2;
				break;
			case '%':
				if(p-v<2) goto err1;
				if(*--p != 0)
					*(p-1) = (int)*(p-1) % (int)*p;
				else
					goto err2;
				break;
			case SIN:
				if(p-v<1) goto err1;
				*(p-1)=sin(*(p-1));
				break;
			case COS:
				if(p-v<1) goto err1;
				*(p-1)=cos(*(p-1));
				break;
			case TAN:
				if(p-v<1) goto err1;
				*(p-1)=tan(*(p-1));
				break;
			case EXP:
				if(p-v<1) goto err1;
				*(p-1)=exp(*(p-1));
				break;
			case POW:
				if(p-v<1) goto err1;
				p--;
				*(p-1)=pow(*(p-1),*p);
				break;
			default:
				goto err3;
				//break;
			}
		}
	}
	for(i=0;i<p-v;i++)
		printf("%g  ",*(v+i));
	printf("\n");
	return 0;
err1:
	printf("error:lack of numeric operand\n");
	return 1;
err2:
	printf("error: zero divisor\n");
	return 2;
err3:
	printf("error: unknown command %s\n", argv[i]);
	return 3;
}
//getop:get next character or operator
int getop(char *s)
{
	if(!strncmp(s,"sin",3))
		return SIN;
	if(!strncmp(s,"cos",3))
		return COS;
	if(!strncmp(s,"tan",3))
		return TAN;
	if(!strncmp(s,"pow",3))
		return POW;
	if(!strncmp(s,"exp",3))
		return EXP;
	return *s;
}
