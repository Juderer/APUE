#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
	int fd;

	if ((fd=creat("file.hole", 0666)) < 0)
		perror("creat");

	if (write(fd, buf1, 10) != 10)
		perror("write buf1");

	if (lseek(fd, 40, SEEK_SET) < 0)
		perror("lseek");

	if (write(fd, buf2, 10) != 10)
		perror("write buf2");

	exit(0);		
}
