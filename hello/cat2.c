/*
 * cat: concatenate files, version 2
 * without error detecting
 */

#include <fcntl.h>
#include "syscalls.h"

char *pname;

int putfile(int fd);
int fileopen(char *name);

int main(int argc,char *argv[])
{
	//int f;
	pname=*argv;

	if(argc==1)
		putfile(0);
	else
		while(--argc>0){
			putfile(fileopen(*++argv));
			//if(!!f)
				//close(f);
		}
	return 0;
}

static char buf[BUFSIZ];

int putfile(int fd)
{
	int n;
	while(n=read(fd,buf,BUFSIZ)>0)
		write(1,buf,n);
	return n;
}

int fileopen(char *name)
{
	if(*name=='-' && name[1]==0)
		return 1;
	return open(name,O_RDONLY,0);
}
