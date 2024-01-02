#include <fcntl.h>
#include <stdio.h>

// 이미 열린 file desciprtor에 대해 표준 입출력 스트림 연결

int main(void)
{
	char *fname = "test.txt";
	int fd;
	FILE *fp;

	if((fd = open(fname, O_WRONLY)) > 0)
		printf("Success!!\nFile descriptor: %d\n", fd);
	else printf("failed\n");

	if((fp = fdopen(fd, "w")) != NULL)
		printf("fdopen() Success!!\n");
	else printf("fdopen() failed\n");

	fprintf(fp, "It's test script\n");
	fclose(fp);
}
