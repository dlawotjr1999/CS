#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <stdlib.h>

#define TIMEOUT 20

// int poll(struct pollfd *fds, unsigned int nfds, int timeout);
/*
	struct pollfd {
		int fd;	// file desciptor
		short events;	// 감시할 event
		short revents;	// 발생한 event
	}
*/
/*
	설정 가능한 event :

	- POLLIN : 읽을 데이터가 존재한다
	- POLLRDNORM : 이란 데이터를 읽을 수 있다
	- POLLRDBAND : 우선권이 있는 데이터를 읽을 수 있다
	- POLLPRI : 시급히 읽을 데이터가 존재한다
	- POLLOUT : 쓰기가 block되지 않을 것이다
	- POLLWRNORM : 일반 데이터 쓰기가 block되지 않을 것이다
	- POLLWRBAND : 우선권이 있는 데이터 쓰기가 block되지 않을 것이다
	- POLLMSG : SIGPOLL 메시지가 사용 가능하다

	설정 가능한 revents :

	- POLLER : 주어진 fd에 에러가 있다
	- POLLHUP : 주어진 fd에서 이벤트가 지체되고 있다
	- POLLNVAL : 주어진 fd가 유효하지 않다
*/


int main(void)
{
	struct pollfd fds[2];
	int ret, fd1, fd2;

	fd1 = open("./np1", O_RDONLY);
	if(fd1 < 0) {
		printf("pipe file 1 open fail\n");
		return 1;
	}
	fd2 = open("./np2", O_RDONLY);
	if(fd2 < 0) {
		printf("pipe file 2 open fail\n");
		return 1;
	}

	fds[0].fd = fd1;
	fds[0].events = POLLIN;

	fds[1].fd = fd2;
	fds[1].events = POLLIN;

	ret = poll(fds, 2, TIMEOUT * 1000);

	if(ret == -1) return 1; // poll error
	else if(!ret) return 0; // timeout

	if(fds[0].revents & POLLIN) {
		printf("stdin is readable\n");
	}
	if(fds[1].revents & POLLIN) {
		printf("stdout is writable\n");
	}
	return 0;
}
