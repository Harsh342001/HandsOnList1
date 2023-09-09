#include<stdio.h>
#include<sched.h>
#include<unistd.h>

int main(){
	int pid = getpid();
	int policy ;
	

	policy = sched_getscheduler(pid);

	if(policy == -1){
		perror("sched_getscheduler failed execution \n");
		return -1;
	}

	printf("Current scheduling policy is : \n");
	switch(policy){
	case SCHED_FIFO:
		printf("FIFO (First-In-First-Out) policy \n");
		break;
	case SCHED_RR:
		printf("RR (Round Robin) policy \n");
		break;
	case SCHED_OTHER:
		printf("SCHED_OTHER policy \n");
		break;
	default:
		printf("Unknown \n");
		break;
	}

	int newPolicy = SCHED_FIFO;
	struct sched_param params;
	params.sched_priority = 50;

	int set_scheduler = sched_setscheduler(pid,newPolicy,&params);

	if(set_scheduler == -1){
		perror("Error occured : Couldn't change scheduling policy of the process \n");
		return -1;
	}
   
   int modified_policy = sched_getscheduler(pid);

	printf("Modified scheduling policy is : \n");
	switch(modified_policy){
	case SCHED_FIFO:
		printf("FIFO (First-In-First-Out) policy \n");
		break;
	case SCHED_RR:
		printf("RR (Round Robin) policy \n");
		break;
	case SCHED_OTHER:
		printf("SCHED_OTHER policy \n");
		break;
	default:
		printf("Unknown \n");
		break;
	}

return -1;	

}

