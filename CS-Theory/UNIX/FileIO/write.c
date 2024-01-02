#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// ssize_t write(int fd, const void *buf, size_t count)

int main(void)
{
	int fd;
	const char *buf = "My ship is solid!";

	fd = open("test.txt", O_WRONLY);
	if(fd == -1) {
		perror("open()");
		exit(-1);
	}
	write(fd, buf, sizeof(buf));
	
	return 0;
}
