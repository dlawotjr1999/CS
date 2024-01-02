#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int fd;
	const char *buf = "The wizard of last century";

	fd = open("test.txt", O_RDWR | O_CREAT, 0666);
	if(fd < 0) {
		perror("open");
		exit(-1);
	}

	// count = sizeof(word);
	// nr = write(fd, &buf,strlen(buf)); 
	ssize_t ret, nr;
	int len = strlen(buf);

	while(len != 0 && (ret = write(fd, buf, len)) != 0) {
		if(ret == -1) {
			if(errno == EINTR) continue;
			perror("write");
			break;
		}
		len -= ret;
		buf += ret;
	}
	if(nr == -1) {
		fprintf(stderr, "%d", errno);
	}
	return 0;
}
