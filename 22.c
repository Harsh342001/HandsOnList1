/*
============================================================================
Name : 22.c
Author : Harsh Ranpariya
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
				parent processes. Check output of the file.
Date: 28th Aug, 2023.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd = open("22.txt",O_RDWR | O_CREAT);
	if(fd == -1){
		printf("Error occured while opening file");
	}
	char buffer_parent[100] = "This content is written by parent";
	char buffer_child[100] = "This content is written by child";
	
	int fork_value = fork();
	if(fork_value == -1){
		printf("Error occured");
	}
	else if(fork_value == 0){
		write(fd, &buffer_child, sizeof(buffer_child));
	}
	else{
		write(fd , &buffer_parent, sizeof(buffer_parent));
	}

	int closefd = close(fd);

	if(closefd == -1){
		printf("couldn't close the file");
	}

	return  0;		

}