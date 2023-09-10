/*
============================================================================
Name : 27_execle.c
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
 	char *myenv[] = {"MYVAR=Hello", NULL};

 	int execle_ret = execle("/bin/ls", "ls","-l", NULL,myenv);
 	if(execle_ret == -1){
 		printf("error occured , Execution of execle failed \n");
 		return -1;
 	}

 	return 0;
 }