#include <ctype.h>
#include <stdio.h>
#include "getline.h"

double atof(char []);

int main()
{
	char s[MAXLINE];
	double d;

	printf("please input a flout\n");
	getline(s,MAXLINE);
	d=atof(s);
	printf("the value of d is %g\n",d);

	return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if(s[i]=='e' || s[i]=='E'){
		int pe,sign2 = (s[++i]=='-')?-1:1; //dose this work ? yes
		//~ sign2 = (s[++i]=='-')?-1:1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for(pe=0;isdigit(s[i]);i++)
			pe = pe*10 + s[i] - '0';
		if(sign2==-1){
			while(--pe>0)
				power *=10.0;
		}else{
			while(--pe>0)
				power /=10.0;
		}
	}

	return sign * val / power;
}
