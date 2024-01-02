#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;

	// O_EXCL 플래그는 파일이 이미 있으면 해당 파일을 생성하지 않고 오류 메세지를 출력
	fd = open("test.txt", O_CREAT | O_EXCL, 0644);
	if(fd < 0) {
		perror("open");
		exit(1);
	}
	close(fd);
}
