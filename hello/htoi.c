#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
	char s[100];
	int i=0;
	printf("please input a integer of hex\n");
	scanf("%s",&s);
	i=htoi(s);
	printf("the value of s[] is %s\n",s);
	printf("the value of hex of i is %x \n",i);
	printf("the value of dec of i is %d \n",i);
	return 0;
}

int htoi(char s[])//convert a string of hex to int
{
	int i=0,hi=0;
	while(s[i]!='\0' && s[i]!='\n'){
		if(isdigit(s[i])){
			hi*=0x10;
			hi+=s[i]-'1'+1;
		}
		if(s[i]>='a' && s[i]<='f'){
			hi*=0x10;
			hi+=s[i]-'a'+0xa;
		}
		if(s[i]>='A' && s[i]<='F'){
			hi*=0x10;
			hi+=s[i]-'A'+0xa;
		}
		i++;
	}
	return hi;
}
