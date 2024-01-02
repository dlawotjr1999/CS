#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 2

int main(void)
{
	int fd;
	char buf[BUFSIZE];

	fd = open("test.txt", O_RDONLY);
	if(fd < 0) {
		perror("open");
		exit(-1);
	}

	// count = sizeof(word);
	// nr = read(fd, &buf,strlen(buf)); 
	unsigned long word;
	ssize_t nr, ret;
	int len = strlen(buf);
	
	// fd에서 몇 바이트를 읽어서 word에 저장한다
	nr = read(fd, &word, sizeof(unsigned long));
	if(nr == -1) {

	}
	while(len != 0 && (ret = read(fd, buf, len)) != 0) {
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
