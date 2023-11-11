/*

Aim
To create a file and to write contents.
Algorithm
1. Declare a character buffer buf to store 100 bytes.
2. Get the new filename as command line argument.
3. Create a file with the given name using open system call with O_CREAT and
O_TRUNC options.
4. Check the file descriptor.
a) If file creation is unsuccessful, then stop.
5. Get input from the console until user types Ctrl+D
a) Read 100 bytes (max.) from console and store onto buf using read system call
b) Write length of buf onto file using write system call.
6. Close the file using close system call.
7. Stop

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd, n, len;
	char buf[100];
	if (argc != 2)	{
		printf("Usage: ./a.out <filename>\n");
		exit(-1);
	}
	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) {
		printf("File creation problem\n");
		exit(-1);
	}
	printf("Press Ctrl+D at end in a new line:\n");
	while((n = read(0, buf, sizeof(buf))) > 0)	{
		len = strlen(buf);
		write(fd, buf, len);
	}
	close(fd);
}
