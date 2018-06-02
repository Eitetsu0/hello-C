#include <stdio.h>
// echo command-line arguments
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");
	return 0;
}
