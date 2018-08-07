#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat statbuf;
	struct utimbuf timebuf;

	for (i = 1; i < argc; i++) {
		if (stat(argv[i], &statbuf) < 0) {
			printf("%s: stat error\n", argv[i]);
			continue;
		}

		if (open(argv[i], O_RDWR | O_TRUNC) < 0) {
			printf("%s: open error\n", argv[i]);
			continue;
		}

		timebuf.actime = statbuf.st_atime;
		timebuf.modtime = statbuf.st_mtime;
		if (utime(argv[i], &timebuf) < 0) {
			printf("%s: utime error\n", argv[i]);
			continue;
		}
	}

	exit(0);
}
