#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd, nr;
	char c, *fname = "/dev/tty"; // current I/O console

	if((fd=open(fname, O_RDONLY | O_NONBLOCK)) < 0) {
		perror("open()");
		exit(-1);
	}
	for(;;) {
		if((nr = read(fd, &c, 1)) > 0) {
			printf("%c\n", c);
			exit(0);
		}
		else if(nr == -1) {
			// interrupt errno
			if(errno == EINTR) printf("."); 
			// full buffer errno
			if(errno == EAGAIN) printf("*"); 
		}
		else break;
	}
	close(fd);
}
