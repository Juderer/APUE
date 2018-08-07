#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int accmode, val;
		
	if (argc != 2) {
		perror("usage: ./out <descriptor>\n");
		exit(-1);
	}

	if ((val=fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
		printf("fcntl error for fd %d\n", atoi(argv[1]));
		exit(-1);
	}

	accmode = val & O_ACCMODE;
	if (accmode == O_RDONLY) 
		printf("read only");
	else if (accmode == O_WRONLY)
		printf("write only");
	else if (accmode == O_RDWR)
		printf("read and write");
	else { 
		perror("unknown access mode\n");
		exit(-1);
	}

	if (val & O_APPEND)
		printf(", append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
	if (val & O_SYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');

	exit(0);
}
