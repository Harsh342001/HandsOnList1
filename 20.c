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