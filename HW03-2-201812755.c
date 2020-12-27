#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int n, status, fd[2];
	int parentsum = 0;
	printf("Enter the number of child process: ");
	scanf("%d", &n);

	int pid[n], sumArray[n];

	for(int i = 0; i < n; i++){
		int sum = 0;
		pipe(fd);
		pid[i] = fork();
		if (pid[i] == 0) {
			close(fd[0]);
			printf("[child no. %d(pid %d)] ", i+1, getpid());
			srand(time(NULL));
			for(int i = 0; i < 10; i++){
				sum = sum + rand() % 10;
			}
			printf("sum = %d\n", sum);
			write(fd[1], &sum, sizeof(int));
			sleep(1);
			exit(0);
		} else {
			close(fd[1]);
			read(fd[0], &sumArray[i], sizeof(int));
			sleep(1);
		}
	}
	for(int i = 0; i < n; i++){
		parentsum = parentsum + sumArray[i];
	}
	printf("[parent] total sum: %d\n", parentsum);
}
