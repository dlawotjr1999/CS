#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// ssize_t read(int fd, void *buf, size_t len)
// 호출할 때마다 fd가 참조하는 파일의 현재 파일 offset에서 len 바이트만큼 buf로 읽어들인다.

int main(void) 
{
	int fd, linecnt = 0, cnt;
	char c;
	char *fname = "test.txt";

	if((fd = open(fname, O_RDONLY)) < 0)
	{
		perror("open()");
		exit(-1);
	}
	while((cnt = read(fd, &c, 1)) > 0) {
		if(c=='\n') linecnt++;		
	}
	printf("Total line:%d\n", linecnt);
	close(fd);
	return 0;
}
