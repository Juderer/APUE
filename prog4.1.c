#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat statbuf;
	char *ptr;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (stat(argv[i], &statbuf) < 0) {
			printf("stat error\n");
			continue;
		}

		if (S_ISREG(statbuf.st_mode))
			ptr = "regular";
		else if (S_ISLNK(statbuf.st_mode))
			ptr = "symbolic link";
		else
			ptr = "others";
		printf("%s\n", ptr);
	}
	exit(0);
}
