/*
============================================================================
Name : 10.c
Author : Harsh Ranpariya
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){

	char buffer[20];

	int stdInput = read(0, buffer, 20);

	int fd_read = open("test10.txt", O_WRONLY);

	if(fd_read == -1){
		printf("Error occured while opening file");
		return -1;
	}

	int f_write = write(fd_read, &buffer, 10);

	int ret_lseek = lseek(fd_read, 10, SEEK_CUR);

	printf("return value of lseek: %d", ret_lseek );

    int f_write2 = write(fd_read, &buffer, 10);

    int fd_close = close(fd_read);

    if(fd_close == -1){
    	printf("Error occured while closing file");
    	return -1;
    }
}