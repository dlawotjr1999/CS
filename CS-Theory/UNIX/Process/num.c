#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int num;
	int sum = 0, mul = 1;
	pid_t pid;

	scanf("%d", &num);
	
	if((pid = fork()) > 0) {
		for(int i = 1; i <= num; i++)
			sum += i;
	}

	else if(pid == 0) {
		for(int i = num; i >= 1; i--)
			mul *= i;
	}
	write(1, &sum, 3);
	write(1, &mul, 3);

	return 0;
}
