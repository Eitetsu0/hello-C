#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <fcntl.h>

int main()
{
	char *argv[]={"showenv", NULL},
	*envp[]={"foo=bar", "bar=foo", NULL};
	execve("./showenv",argv,envp);
	perror("exeve failed.");
	return 0;
}

