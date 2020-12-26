#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#define MAX_SIZE 10

void intHandler()
{
	if(unlink("pipe1") == -1 || unlink("pipe2") == -1 || unlink("pipe3") == -1 || unlink("pipe4") == -1) {
		printf("failed: unlink\n");
		exit(1);
	} else {
		exit(1);
	}
}

int main(int argc, char* argv[])
{
	int fd2, fd3, num;
	char numstr[MAX_SIZE];
	printf("[Baekgu]: 3~69 369!\n");

	signal(SIGINT, intHandler);

	if(argc > 1) {
		num = 1;
		unlink("pipe1");
		unlink("pipe2");
		unlink("pipe3");
		unlink("pipe4");

		if(mkfifo("pipe1", 0666) == -1 || mkfifo("pipe2", 0666) == -1 || mkfifo("pipe3", 0666) == -1 || mkfifo("pipe4", 0666) == -1) {
			printf("failed: mkfifo\n");
			exit(1);
		}

		fd2 = open("pipe2", O_RDONLY);
		fd3 = open("pipe3", O_WRONLY);

		if(fd2 == -1 || fd3 == -1) {
			printf("failed: open\n");
			exit(1);
		}

		printf("[Baekgu]: %d!\n", num);
		num++;
		write(fd3, &num, sizeof(int));
	} else {
		fd2 = open("pipe2", O_RDONLY);
		fd3 = open("pipe3", O_WRONLY);

		if(fd2 == -1 || fd3 == -1) {
			printf("failed: open\n");
			exit(1);
		}
	}
	for(int i = 0; i < 25; i++) {
		int flag = 0;
		read(fd2, &num, sizeof(int));
		sleep(1);
		printf("[Baekgu]: ");
		sprintf(numstr, "%d", num);
		for(int j = 0; j < MAX_SIZE; j++) {
			if(numstr[j] == '3' || numstr[j] == '6' || numstr[j] == '9') {
				flag++;
			}
		}
		if(flag > 0){
			for(int j = 0; j < flag; j++) {
				printf("clap! ");
			}
			printf("[%d]", num);
		} else {
			printf("%d!",num);
		}
		printf("\n");
		num++;
		write(fd3, &num, sizeof(int));
	}
}

