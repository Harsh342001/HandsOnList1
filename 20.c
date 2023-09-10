/*
============================================================================
Name : 20.c
Author : Harsh Ranpariya
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int which = PRIO_PROCESS;
	int pid ;
	pid = getpid();
	int proc_prio;
	nice(10);
	while(1){
		
	}
	proc_prio = getpriority(which,pid);
	printf("priority of the process is : %d \n",  proc_prio);
	return 0;	
}