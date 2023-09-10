/*
============================================================================
Name : 16.c
Author : Harsh Ranpariya
Description : 16.Write a program to perform mandatory locking.
				a. Implement write lock
				b. Implement read lock
Date: 28th Aug, 2023.
============================================================================
*/

#include<fcntl.h>
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	struct flock fl;
	int fd = open("16.txt" , O_RDWR|O_CREAT);
	int exit = 1;

	if(fd == -1){
		perror("unable to open file");
		return -1;
	}

	while(exit){
		printf("Enter the type of lock you wanna aquire \n");
		printf("Enter 'r' to aquire read lock \n");
		printf("Enter 'w' to aquire write lock \n");
		printf("enter 'e' to exit \n" );

		char c ;
		scanf(" %c" , &c);

		switch(c){
		case	'r' :  
				fl.l_type = F_RDLCK; 
				fl.l_whence = SEEK_SET;
				fl.l_start = 0;
				fl.l_len = 0;
				fl.l_pid = getpid();
	
				printf("Before acquiring read lock \n");

				int errr = fcntl(fd, F_SETLKW, &fl);

					printf("read lock acquired \n");
					printf("inside the critical section\n");
					printf("please enter a character to release the lock\n");
					char chr;
					scanf(" %c" , &chr);


					fl.l_type = F_UNLCK;
					fcntl(fd , F_SETLK , &fl);
					printf("Exited from  critical section \n \n");
				// }
				
				close(fd);
				
				break;

		case	'w' : 	

				fl.l_type = F_WRLCK; 
				fl.l_whence = SEEK_SET;
				fl.l_start = 0;
				fl.l_len = 0;
				fl.l_pid = getpid();
	
				printf("Before acquiring write lock \n");	

				int errw = fcntl(fd, F_SETLKW, &fl);
				
					printf("write lock acquired \n");
					printf("inside the critical section\n");
					printf("please enter a character to release the lock");
					char chw;
					scanf(" %c" , &chw);
					
					fl.l_type = F_UNLCK;
					fcntl(fd , F_SETLK , &fl);
					printf("Exited from  critical section \n \n");
				// }
				
				close(fd);
				
				break;
		case	'e' : 
			 	exit = 0;
			 	break;	

		default : 
			printf("enter valid choice");	 	
		}

			
		
	}

	return 0;
}