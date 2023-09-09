#include<unistd.h>
#include<stdio.h>
 int main(){
 	char *args[] = {"ls" , "-Rl" , NULL};

 	int execvp_ret = execvp("ls", args);
 	if(execvp_ret == -1){
 		printf("error occured , Execution of execv failed \n");
 		return -1;
 	}

 	return 0;
 }