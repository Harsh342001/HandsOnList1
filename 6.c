/*
============================================================================
Name : 6.c
Author : Harsh Ranpariya
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/types.h>
#include <stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>

int main(){
	
	char buffer[20];

	int inputRead = read(0, buffer, 20);
	int OutputWritten = write(1,buffer,20);

	if(inputRead == -1 && OutputWritten == -1){
		printf("Error");
	}
	return 0;
}