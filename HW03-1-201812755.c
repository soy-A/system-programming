#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child(int count, int n)
{
	int pid, parentpid, childpid, status;
	if(count < n) {
		parentpid = getpid();
		pid = fork();
		if (pid == 0) {
			printf("child process of [%d], %d start\n", parentpid, getpid());
			count++;
			sleep(1);
			child(count, n);
			exit(1);
		}
		childpid = wait(&status);
		printf("child process of [%d], %d done\n", getpid(), childpid);
		sleep(1);
	}
}

int main()
{
	int n, count = 0;
	printf("Enter the number of child process: ");
	scanf("%d", &n);

	child(count, n);
}
