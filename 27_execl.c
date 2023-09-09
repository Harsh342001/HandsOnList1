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