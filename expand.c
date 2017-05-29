#include <stdio.h>
#include <ctype.h>

#define MAX 1000

void expand(char s1[],char s2[]);

int main()
{
    char s1[MAX],s2[MAX];
    printf("please input a string \n");
//	scanf("%s",s1);
	int i=0;
	while((s1[i++]=getchar())!='\n');
	s1[i]='\0';
    expand(s1,s2);
    printf("s1:%s\n\ns2:%s\n",s1,s2);
    return 0;
}

//expand a-z 0-9 to abc...z 012..9
void expand(char s1[],char s2[])
{
    int i=0,j=0;
    char t;

    while((s2[j++]=s1[i++])!='\0'){
        while(s1[i]=='-' && isalnum(s1[i-1]) && s1[i-1]<=s1[i+1]){
            t=s1[i-1]+1;
            while((s2[j++]=t++)!=s1[i+1]);
            i+=2;
        }
    }
}
