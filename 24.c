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
