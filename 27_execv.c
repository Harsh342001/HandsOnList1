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