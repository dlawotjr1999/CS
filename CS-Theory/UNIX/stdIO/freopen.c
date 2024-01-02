#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// freopen의 동작
// fd = open(pathname, type);
// dup2(fd, fd->_fileno);
// 전형적으로 미리 정의된 stream들 중 하나로 명시된 파일을 개방하고자 하는 경우 사용

int main(void)
{
	char *fname = "test.txt";
	FILE *fp;

	printf("First printf is on the screen.\n");
	if((fp = freopen(fname, "w", stdout)) == NULL)
	{
		perror("freopen");
		exit(-1);
	}
	printf("Second printf is in this file.\n");
}
