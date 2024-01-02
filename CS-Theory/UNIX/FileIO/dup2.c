#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int dup2(int filedes, int newfiledes);
// 사용자가 지정한 fd를 사용하여 fd를 복제
// 만약 newfiledes가 가리키는 곳에 이미 entry가 존재할 경우 닫고 할당 

int main(void)
{
	char *fname = "test.txt";
	int fd;

	if((fd = creat(fname, 0666)) < 0) {
		perror("creat()");
		exit(-1);
	}

	printf("First printf is on the screen.\n");
	dup2(fd, 1);
	printf("Second printf is in this file.\n");

	return 0;
}
