#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 10

// ssize_t pread(int fd, void *buffer, size_t count, off_t pos);
// ssize_t pwirte(int fd, const void *buffer, size_t count, off_t pos);

int main(void)
{
	char buffer[BUF_SIZE + 1];

	int fd = open("test.txt", O_RDWR);
	if(fd < 0) {
		perror("open");
		exit(-1);
	}

	off_t offset = lseek(fd, 0, SEEK_CUR);
	printf("offset = %ld\n", offset);

	// pread
	int bytes = pread(fd, buffer, BUF_SIZE, 35);
	printf("in buffer : %s\n", buffer);

	offset = lseek(fd, 0, SEEK_CUR);
	printf("Offset after pread = %ld\n", offset);

	// pwrite
	bytes = pwrite(fd, "0000000000", 10, 15);

	offset = lseek(fd, 0, SEEK_CUR);
	printf("Offset after pwrite = %ld\n", offset);

	close(fd);

	return 0;
}
