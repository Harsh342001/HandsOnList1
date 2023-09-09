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