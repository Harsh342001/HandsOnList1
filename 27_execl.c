/*
============================================================================
Name : 27_execl.c
Author : Harsh Ranpariya
Description : 27. Write a program to execute ls -Rl by the following system calls
				a. execl
				b. execlp
				c. execled. execv
				e. execvp
Date: 28th Aug, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
 int main(){
 	int execl_ret = execl("/bin/ls", "ls","-l", NULL);
 	if(execl_ret == -1){
 		printf("error occured , Execution of execl failed \n");
 		return -1;
 	}

 	return 0;
 }