#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PORTNUM 9000

int main(void)
{
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	// socket 함수의 인자로 AF_INET과 SOCK_STREAM을 지정해 소켓을 생성한다
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	// 서버의 IP 주소(192.168.147.129)를 지정하고 포트 번호는 9000으로 지정해 소켓 주소 구조체를 설정한다
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.147.129");

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(sd, 5)) {
		perror("listen");
		exit(1);
	}

	if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
		perror("accept");
		exit(1);
	}

	sprintf(buf, "Your Ip address is %s", inet_ntoa(cli.sin_addr));
	if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
		perror("send");
		exit(1);
	}

	close(ns);
	close(sd);
}
