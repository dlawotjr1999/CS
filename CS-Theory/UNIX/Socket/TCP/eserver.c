#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9003

int main(void)
{
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	printf("** Creat Socket");

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.147.129");

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}
	printf("** Bind Socket\n");

	if(listen(sd, 5)) {
		perror("listen");
		exit(1);
	}
	while(1) {
		if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
			perror("accept");
			exit(1);
		}
		printf("** Accept Client\n");

		switch(fork()) {
			case 0:
				// 클라이언트와 통신할 수 있는 소켓 기술자(ns)를 표준 입력과 표준 출력으로 복사한다
				// 이후 execl 함수로 han 프로세스를 실행한다 
				printf("** Fork Client\n");
				close(sd);
				dup2(ns, STDIN_FILENO);
				dup2(ns, STDOUT_FILENO);
				close(ns);
				execl("./han", "han", (char *)0);
			}
		close(ns);
	}
}
