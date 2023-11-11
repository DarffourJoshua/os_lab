/*

Aim
To read the given file and to display file contents.
Algorithm
1.
2.
3.
4.
Declare a character buffer buf to store 100 bytes.
Get existing filename as command line argument.
Open the file for reading using open system call with O_RDONLY option.
Check the file descriptor.
a) If file does not exist, then stop.
5. Read until end-of-file using read system call.
a) Read 100 bytes (max.) from file and print it
6. Close the file using close system call.
7. Stop

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	
#include <unistd.h>


int main(int argc, char *argv[]) {
	int fd,i;
	char buf[100];
	if (argc < 2) {
		printf("Usage: ./a.out <filename>\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		printf("%s file does not exist\n", argv[1]);
		exit(-1);
	}
	printf("Contents of the file %s is : \n", argv[1]);
	while(read(fd, buf, sizeof(buf)) > 0)
		printf("%s", buf);
	close(fd);
}
