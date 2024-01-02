#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define TIMEOUT 5
#define BUF_LEN 1024

//  int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
/* 
    FD_CUR(int fd, fd_set *set); // fd 하나를 집합에서 제거
	FD_ISSET(int fd, fd_set *set); // 주어진 fd가 fd 집합에 속해 있는지 여부를 확인
	FD_SET(int fd, fd_set *set); // 주어진 fd를 fd 집합에 추가
	FD_ZERO(fd_set *set); // 주어진 fd 집합을 모두 초기화. 모든 비트를 0으로 설정
*/

/*
	struct timeval {
		long tv_sec; // 초
		long tv_usec; // 마이크로 초
	}	
*/
// pselect의 경우 timeout 인자로 timeval 구조체 대신 timespec 구조체를 사용한다
// pselect는 timeout 인자를 변경하지 않는다
// select 시스템 콜은 sigmask 인자를 받지 않는다

int main(void)
{
	struct timeval tv;
	fd_set readfds;
	int ret, mfd;

	mfd = open("/dev/input/mouse0", O_RDONLY); // 마우스 입력장치에 대한 fd를 제공하는 device file
	if(mfd < 0) {
		printf("mouse device open fail\n");
		return 1;
	}

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);
	FD_SET(mfd, &readfds);

	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	ret = select(mfd + 1, &readfds, NULL, NULL, &tv);
	if(ret == -1) return 1; // select error
	else if(!ret) return 0; // timeout

	if(FD_ISSET(STDIN_FILENO, &readfds)) {
		char buf[BUF_LEN + 1];
		int len;

		len = read(STDIN_FILENO, buf, BUF_LEN);
		if(len == -1) return 1; // read error
		if(len) {
			buf[len] = '0';
			printf("read: %s\n", buf);
		}
		return 0;
	}
	if(FD_ISSET(mfd, &readfds)) {
		printf("mouse event occurred\n");
		return 0;
	}
	fprintf(stderr, "This should not happen!\n");
	return 1;
}
