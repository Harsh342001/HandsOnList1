#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int status;

	int child1  = fork();

	if(child1 == 0){
		printf("Inside 1st child process with process id: %d \n", getpid());
		sleep(3);
		printf("child process with pid : %d  exited \n" , getpid());
		exit(1);
	}

	int child2  = fork();

	if(child2 == 0){
		printf("Inside 2nd child process with process id: %d \n", getpid());
		sleep(10);
		printf("child process with pid : %d  exited \n" , getpid());
		exit(2);
	}

	int child3  = fork();

	if(child3 == 0){
		printf("Inside 3rd child process with process id: %d \n", getpid());
		sleep(15);
		printf("child process with pid : %d  exited \n" , getpid());
		exit(3);
	}

	int wait_pid = waitpid(child1, &status, 0);
	if(wait_pid == -1){
		printf("Error occured , waitpid system call failed \n");
		return -1;
	}

	if(WIFEXITED(status)){
		printf("child for which parent was waiting exited normally \n");
	}
	else{
		printf("child for which parent was waiting did not exit normally \n");
	}


	return 0;
	
}