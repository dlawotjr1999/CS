#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9004

int main(void)
{
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	printf("** Create Socket\n");

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.147.129");

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}
	printf("Bind Socket\n");

	if(listen(sd, 5)) {
		perror("listen");
		exit(1);
	}
	printf("Listen Socket\n");

	while(1) {
		if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
			perror("accept");
			exit(1);
		}
		printf("Accept Client\n");

		switch(fork()) {
			case 0 :
				printf("Fork Client\n");
				close(sd);
				// 클라이언트와 통신할 수 있는 소켓을 버퍼에 저장한다
				sprintf(buf, "%d", ns);
				// execlp 함수를 호출하면서 소켓 기술자를 인자로 지정한다
				// eseclp 함수를 호출했으므로 자식 프로세스는 bit 프로세스 이미지로 바뀐다
				// 이후 buf로 지정한 인자는 bit 프로세스의 명령행 인자로 전달된다
				execlp("./bit", "bit", buf, (char *)0);
				close(ns);
		}
		close(ns);
	}
}
