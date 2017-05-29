#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
int main()
{
	//~ int i=1;
	pid_t pid;
	//int pid;

	printf("Now only one process\n");
	printf("Calling fork... \n");
	pid=fork();
	if (!pid){
		printf("I’m the child\n");
		//return 235;
		printf("Executing \"exec\":\n\n");
		execl("./YangHuiTriangle","YangHuiTriangle",NULL);
		/* 如果 execl 返回,说明调用失败 */
		perror("execl failed to run ls");
		exit(1);
	}
	else if (pid>0){
		printf("I’m the parent, child has pid %d\n",pid);
		//~ while(i++<pid)
			//~ printf("%d ",i);
		wait(&pid);
		printf("\nparent:child exited with %d\n",(pid>>8)&0xff);
	}
	else//pid==-1
		printf("Fork fail!\n");
	return 0;
}
