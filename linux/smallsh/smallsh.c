#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "smallsh.h"

/* 程序缓冲区和指针 */
static char inpbuf[MAXBUF],tokbuf[2*MAXBUF],
			*ptr =inpbuf,*tok=tokbuf;
/* userin()函数 */
int userin(char * p)
{
	int c,count;
	ptr=inpbuf;
	tok=tokbuf;
	/* 显示提示 */
	printf("%s ",p);
	count=0;
	for (count=0;;) {
		if ((c=getchar())==EOF)
			return(EOF);
		if (count<MAXBUF)
			inpbuf[count++]=c;
		if (c =='\n' && count <MAXBUF) {
			inpbuf[count]='\0';
			return(count);
		}
		/* 如果行过长重新输入 */
		if (c=='\n') {
			printf("smallsh:input line too long\n");
			count=0;
			printf("%s ",p);
		}
	}
}

/**
 * gettok:从 userin 构造的命令行缓冲区中分析出命令名和参数
 * @return : see smallsh.h
 */
int gettok(char** output)
{
	int inarg(char c);
	int type;
	*output=tok;
	/* 首先去除空白字符 */
	while(*ptr==' '||*ptr=='\t')
		ptr++;
	*tok++=*ptr;
	switch(*ptr++) {
	case '\n':
		type=EOL;
		break;
	case '&':
		type=AMPERSAND;
		break;
	case ';':
		type=SEMICOLON;
		break;
	default:
		type=ARG;
		while (inarg(*ptr))
			*tok++=*ptr++;
	}
	*tok++='\0';
	return type;
}

/**
 * int inarg(char c):确定一个字符是否可以作为参数的组成符
 */
static char special[]={' ','\t','*',';','\n','\0'};
int inarg(char c)
{
	char *wrk;
	for(wrk=special;*wrk!='\0';wrk++)
		if(c==*wrk)
			return(0);
	return(1);
}

///
/**
 * procline:
 * 使用函数 gettok()分析命令行,在处理过程中构造一张参数表
 * 遇到换行符或分号时,就调用 runcommand(char*arg[],int where) 来执行被分析的命令行
 */
void procline(void)
{
	int runcommand(char** cline,int where);

	char * arg[MAXARG+1];
	int toktype;
	int narg;
	int type;

	for(narg=0;;) {
		switch(toktype=gettok(&arg[narg])) {
		case ARG:
			if (narg<MAXARG)
			narg++;
			break;
		case EOL:
		case SEMICOLON:
		case AMPERSAND:
			type = (toktype==AMPERSAND)?BACKGROUND:FOREGROUND;
			if (narg!=0) {
				arg[narg]=NULL;
				runcommand(arg,type);
			}
			if (toktype==EOL)
				return;
			narg=0;
			break;
		}
	}
}

/**
 * runcommand :
 * 实现启动命令进程
 * @param where : can be the following value	see "smallsh.h"
 * 				@arg BACKGROUND		将忽略 wait()调用,并且 runcommand
 * 									只显示进程标识符后就返回
 * 				@arg FOREGROUND
 */
int runcommand(char** cline,int where)
{
	int pid,exitstat,ret;

	if((pid=fork())<0) {
		perror("fork fail");
		return(-1);
	}
	if (!pid) { /* 子进程代码 */
		execvp(*cline,cline);
		perror(*cline);
		exit(127);
	}
	/* 父进程代码 */
	/* 后台进程代码 */
	if (where==BACKGROUND) {
		printf("[process id %d]\n",pid);
		return(0);
	}
	/* 前台进程代码 */
	while ((ret=wait(&exitstat))!=pid && ret !=-1)
		;
	return (ret==-1?-1:exitstat);
}

char *prompt="command>";
int main()
{
	while (userin(prompt)!=EOF)
		procline();
	putchar('\n');
	return 0;
}
