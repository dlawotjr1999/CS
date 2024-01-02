#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sig(int sig)
{
	printf("child die (%d)\n", getpid());
}

void main(void)
{
	signal(SIGINT, sig);
	pause();
}
