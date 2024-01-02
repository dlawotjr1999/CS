#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd, flags;

	fd = open("test.txt", O_RDWR);
	if(fd < 0) {
		perror("open");
		exit(1);
	}

	if((flags = fcntl(fd, F_GETFL)) == -1) {
		perror("fcntl");
		exit(1);
	}	

	// 리턴된 플래그 값에 변경할 플래그를 OR로 연결해 새로운 플래그로 저장
	flags |= O_APPEND;
	
	// 새로 저장된 플래그를 F_SETFL 명령으로 설정
	if(fcntl(fd, F_SETFL, flags) == -1) {
		perror("fcntl");
		exit(1);
	}		

	if(write(fd, "Water Goblin\n", 13) != 13)
		perror("write");

	close(fd);
}
