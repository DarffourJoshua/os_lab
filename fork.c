#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int x = 5;
	pid = fork();
	x++;
	
	if (pid < 0) {
		printf("Process creation error\n");
		exit(-1);
	}
	else if (pid == 0) {
		printf("Child Process: \n");
		printf("Process id %d\n", getpid());
		printf("Value of x is %d\n", x);
		printf("Parent Process id %d\n", getppid());
	}
	else {
		printf("Parent Process: \n");
		printf("Process id is %d\n", getpid());
		printf("The value of x is %d\n", x);
		printf("Shell process id is %d\n", getppid());
	}
}
