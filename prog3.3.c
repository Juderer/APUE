#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 8192

int main(int argc, char *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 1)
		if (write(STDOUT_FILENO, buf, n) != n)
			perror("write error");

	if (n < 0)
		perror("read error");

	exit(0);
}
