#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// int truncate(const char* path, off_t len)
// int ftruncate(int fd, off_t len)
// 파일을 특정 길이만큼 잘라내는 시스템 콜

int main(void)
{
	int ret;

	ret = truncate("./test.txt", 8);
	if(ret == -1) {
		perror("truncate");
		return -1;
	}	
	return 0;
}
