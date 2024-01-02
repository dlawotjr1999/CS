#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	if(truncate("test.txt", 10) < 0) {
		perror("truncate error");
		exit(-1);
	}

	return 0;
}
