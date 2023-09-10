/*
============================================================================
Name : 24.c
Author : Harsh Ranpariya
Description : 24. Write a program to create an orphan process.
Date: 28th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fork_val = fork();

	if(fork_val == -1){
		printf("Error occured");
	}
	else if(fork_val == 0){
		printf("child process created corresponding to parent : %d \n" , getppid());
		sleep(10);
		printf("child process after sleep corresponding to parent : %d \n" , getppid());
	}
	else{
		printf("parent process fork call with process id :	 %d,\n",getpid());
		exit(0);
	}
	return 0;
} 
