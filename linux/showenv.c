#include <stdio.h>

extern char** environ;

int main()
{
	char** env=environ;
	while (*env) {
		printf("%s\n",*env++);
	}
	return 0;
}

/**
 * findenv()根据参数给出的字符串 name,扫描环境内容,找出“name=string” 这种形式
 * 的字符串。如果成功,findenv()就返回一个指向这个字符串中”string” 部分的指针。如果不
 * 成功,就返回一个 NULL 指针。
 */
extern char** environ;
char* findenv(char* name)
{
	int pcmp(char* s1, char* s2);
	int len;
	char **p;

	for(p=environ;*p;p++)
	{
		if((len=pcmp(name,*p))>=0 && *(*p+len)=='=')
			return (*p+len+1);
	}
	return NULL;
}

int pcmp(char* s1, char* s2)
{
	int i=0;

	while(*s1) {
		i++;
		if (*s1++!=*s2++)
			return -1;
	}
	return i;
}
