#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char first, last, ch;
	int pid, i;

	if((pid = fork()) > 0) {
		first = 'A';
		last = 'Z';
	}
	else if(pid == 0) {
		first = 'a';
		last = 'z';
		sleep(1);
	}

	for(ch = first; ch <= last; ch++)
		write(1, &ch, 1); // standard out

	return 0;
}
