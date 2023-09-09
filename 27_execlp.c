#include<unistd.h>
#include<stdio.h>
 int main(){

 	int execlp_ret = execlp("ls","ls","-l", NULL);
 	if(execlp_ret == -1){
 		printf("error occured , Execution of execlp failed \n");
 		return -1;
 	}
 	return 0;
 }