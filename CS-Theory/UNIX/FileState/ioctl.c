#include <stdio.h>
#include <unistd.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <fcntl.h>

// int ioctl(int fd, int request, ...);
// ./ioctl /dev/cdrom
// I/O 장치의 제어를 위해 사용되는 함수
// device에 접근하여 장치 정보를 얻어오거나 장치의 값을 변경

int main(int argc, char *argv[])
{
	int fd, ret;
	
	if(argc < 2) return 1; // error
	fd = open(argv[1], O_RDONLY | O_NONBLOCK);
	if(fd < 0) return 1; // error
	ret = ioctl(fd, CDROMEJECT, 0);
	if(ret) return 1; // error
	ret = close(fd);
	if(ret) return 1; // error
	return 0;
}
