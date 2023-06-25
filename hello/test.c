#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "timeout\n"


int main(int argc, char *argv[])
{
	char buf[10];
	int fd, n, i;
	fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
	if(fd<0) {
		perror("open /dev/tty");
		exit(1);
	}
	for(i=0; i<5; i++) {
		n = read(fd, buf, 10);
		if(n>=0)
			break;
		if(errno!=EAGAIN) {
			perror("read /dev/tty");
			exit(1);
		}
		sleep(1);
		write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
	}
	if(i==5)
		write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
	else
		write(STDOUT_FILENO, buf, n);
	close(fd);

	char s[]="root:x::0:root:/root:/bin/bash:";
	char *token=strtok(s,":");
	printf("%s\n",token);
	while((token=strtok(token+strlen(token)+1,":"))!=NULL){
		printf("%s\n",token);
	}

	if(argc<2)
		return EXIT_SUCCESS;

	printf("\nOpening file %s\n\n",argv[1]);
	FILE *f=fopen(argv[1],"r");
	if(f==NULL){
		perror("Open file");
		fprintf(stderr,"File name: %s , errno=%d\n", argv[1],errno);
		exit(EXIT_FAILURE);
	}
	int c;
	while((c=fgetc(f))!=EOF){
		putchar(c);
	}
	fclose(f);

	return 0;
}
