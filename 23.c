/*
============================================================================
Name : 23.c
Author : Harsh Ranpariya
Description : 23. Write a program to create a Zombie state of the running program
Date: 28th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	int fork_value = fork();

	if(fork_value == -1){
		printf("Error occured");
	}
	else if(fork_value == 0){
		printf("Execution of child process %d \n",getpid());
	}
	else{
		printf("Executing parent process \n");
		sleep(30);
	}
}