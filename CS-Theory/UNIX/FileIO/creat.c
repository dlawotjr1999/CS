#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
	char *fname = "2nd test.txt";
	int fd;

	fd = creat(fname, 0666);
	// fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0666)
	if(fd < 0) perror("create()");
	else {
		printf("Success!\n Filename:%s, fd:%d\n", fname, fd);
		close(fd);
	}

	return 0;
}
