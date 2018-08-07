#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct stat statbuf;

	if (stat("foo", &statbuf) < 0)
		printf("stat error for foo\n");
	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISUID) < 0)
		printf("chmod error for foo\n");

	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		printf("chmod error for bar\n");

	exit(0);
}
