#include <stdio.h>
#define MAXLINE 1000

int getline(char line[],int lim);
int strindex(char source[],char searchfor[]);
int strrindex(char source[],char searchfor[]);

int main()
{
	char line[MAXLINE];
	char pattern[MAXLINE];
	int found=0;
	int i;

	printf("input pattern\n");
	i=getline(pattern,MAXLINE);
	if(pattern[i-1]=='\n') pattern[i-1]='\0';
	printf("input FILE\n");
	while(getline(line,	MAXLINE)>0) // 1 should be 0
		if((i=strindex(line,pattern)) >= 0){
			printf("%s",line);
			printf("	index of pattern in this line is %d,right is %d\n",i,strrindex(line,pattern));
			found++;
		}
	return found;
}

//getline:get line into s return length
int getline(char s[],int lim)
{
	int c,i;

	i=0;
	while(--lim>0 && (c=getchar())!=EOF && c!='\n')
		s[i++]=c;
	if(c=='\n') s[i++]=c;
	s[i]='\0';
	return i;
}

//strindex:return index of t in s,-1 if none
int strindex(char s[],char t[])
{
	int i,j,k;

	for(i=0;s[i]!='\0';i++){
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
			;
		if(k>0 && t[k]=='\0')
			return i;
	}
	return -1;
}

//strlindex:return index of t in s from right to left,-1 if none
int strrindex(char s[],char t[])
{
	int i,j,k;

	for(i=0;s[i]!='\0';i++);

	for(i-=1;i>=0;i--){
		for(j=i,k=0;t[k]!='\0' && s[j]!='\0' && s[j]==t[k];j++,k++)
			;
		if(k>0 && t[k]=='\0'){
			return i;
		}
	}
	return -1;
}
