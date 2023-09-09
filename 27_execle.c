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