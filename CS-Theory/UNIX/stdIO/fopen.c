#include <stdio.h>
#include <stdlib.h>

/*
	- "r" or "rb" : O_RDONLY
	- "w" or "wb" : O_WRONLY | O_CREAT | O_TRUNC
	- "a" or "ab" : O_WRONLY | O_APPEND | O_CREAT
	- "r+" or "r+b" or "rb+" : O_RDWR
	- "w+" or "w+b" or "wb+" : O_RDWR | O_CREAT | O_TRUNC
	- "a+" or "a+b" or "ab+" : O_RDWR | O_APPEND | O_CREAT
*/
int main(void)
{
	FILE *fp;

	if((fp = fopen("test.txt", "r")) != NULL) {
		printf("Success!\n");
		printf("Opening \"test.txt\" in \"r\" mode!\n");
		printf("File descriptor of fp: %d\n", fp->_fileno);
	}
	else
	{
		perror("Error");
		exit(-1);
	}
	fclose(fp);

	return 0;
}
