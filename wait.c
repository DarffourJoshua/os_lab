#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*

Aim
To block a parent process until child completes using wait system call.
Algorithm
1. Create a child process using fork system call.
2. If return value is -1 then
	a. Print "Process creation unsuccessfull"
3. Terminate using exit system call.
4. If return value is > 0 then
	a. Suspend parent process until child completes using wait system call
	b. Print "Parent starts"
	c. Print even numbers from 0–10
	d. Print "Parent ends"
5. If return value is 0 then
	a. Print "Child starts"
	b. Print odd numbers from 0–10
	c. Print "Child ends"
6. Stop

*/


int main()	{
	int i, status;
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		printf("\nProcess creation failure\n");
		exit(-1);
	}	else if(pid > 0)	{
		wait(NULL);
		printf ("\nParent starts\nEven Nos: ");
		for (i=2;i<=10;i+=2) {
			printf ("%3d",i);
		}
		printf ("\nParent ends\n");
	}
		else if (pid == 0)	{
		printf ("Child starts\nOdd Nos: ");
		for (i=1;i<10;i+=2)	{
			printf ("%3d",i);
		}
		printf ("\nChild ends\n");
	}
}
