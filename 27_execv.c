/*
============================================================================
Name : 27_execv.c
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
 	char *args[] = {"ls" , "-Rl" , NULL};

 	int execv_ret = execv("/bin/ls", args);
 	if(execv_ret == -1){
 		printf("error occured , Execution of execv failed \n");
 		return -1;
 	}

 	return 0;
 }