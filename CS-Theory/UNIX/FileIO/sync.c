#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// fsync를 호출하면 fd에 mapping된 모든 변경점을 디스크에 기록한다.
// 이때 fd는 반드시 write 모드로 열려야 한다.
// fdatasync는 fsync와 동일하지만 필수적이지 않은 메타데이터는 강제로 디스크에 기록하지 않는다.

int main(void)
{
	int fd, ret;

	fd = open("test.txt", O_WRONLY);
	if(fd < 0) {
		perror("open");
		exit(-1);
	}
	ret = fsync(fd);
	// ret = fdatasync(fd)
	if(ret == -1) {
		perror("fsync error");
		exit(-1);
	}
	/* if(errno == EINVAL) {
	    if(fdatasync(fd) == -1)
			perror("fdatasync");	
		} else perror("fsync);
	 */
	
	return 0;
}
