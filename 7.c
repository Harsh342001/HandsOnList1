/*
============================================================================
Name : 7.c
Author : Harsh Ranpariya
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/types.h>
#include <stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Enter destination file");
		return -1;
	}
	int fd_read = open(argv[1],O_RDONLY);
	int fd_write = open(argv[2] , O_WRONLY|O_CREAT );

	if(fd_read == -1 || fd_write == -1){
		perror("Error occured while performing read/write operation");
		return -1;
	}
	while(1){
		char buf;
		int char_read = read(fd_read, &buf, 1);
		if(char_read == 0){
			break;
		}
		int char_written = write(fd_write,&buf,1);
	}
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);

	if(close_fd_read==-1 || close_fd_write==-1)
                perror("Error occured while closing file\n");
            	return -1;

	return 0;
}