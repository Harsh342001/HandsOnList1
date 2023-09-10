/*
============================================================================
Name : 21.c
Author : Harsh Ranpariya
Description : 21. Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include <sys/resource.h>
int main(){
	int fork_value = fork();
	if(fork_value == -1){
		printf("error occured \n");
		
	}
	else if(fork_value == 0){
		printf("child process id : %d \n", getpid());
	}
	else{
		printf("parent process id : %d \n" , getpid());
	}
}