#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9001

int main(void)
{
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	memset((char *)&sin, '\0', sizeof(cli));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.147.129");

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(sd, 5)) {
		perror("listen");
		exit(1);
	}

	while(1) {
		// accpet 함수를 사용해 클라이언트의 요청이 올 때까지 기다린다
		// 클라이언트의 접속 요청이 오면 새로운 소켓 기술자 ns가 생성되고 이를 통해 클라이언트와 통신한다 
		if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
			perror("accept");
			exit(1);
		}
		// accept 함수를 통해 알아낸 클라이언트의 IP 주소를 문자열로 변환해 버퍼에 저장한다
		sprintf(buf, "%s", inet_ntoa(cli.sin_addr));
		// 어떤 클라이언트가 서버로 접속했는지를 출력한다
		printf("*** Send a Message to Client(%s)\n", buf);
		
		// 서버에서 클라이언트로보낼 간단한 환영 메세지를 작성한다
		strcpy(buf, "Welcome to Network Server!!!");
		// send 함수를 통해 클라이언트로 메세지를 보낸다
		if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
			perror("send");
			exit(1);
		}
		
		// 클라이언트가 보낸 메세지를 recv 함수로 받아서 출력한다
		if(recv(ns, buf, sizeof(buf), 0) == -1) {
			perror("recv");
			exit(1);
		}
		printf("** From Client : %s\n", buf);
		// 작업이 끝나면 클라이언트와 접속할 때 사용한 소켓 기술자를 닫고 다시 40행의 accept 함수를 수행한다
		close(ns);
	}
	close(sd);
}
