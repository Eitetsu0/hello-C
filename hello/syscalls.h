#ifndef SYSCALLS
#define SYSCALLS
#ifndef BUFSIZ
#define BUFSIZ 1
#endif
extern int read(int fd, char *buf, int n);
extern int write(int fd, char *buf, int n);

extern long lseek(int fd, long offset, int origin);
#endif
