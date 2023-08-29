#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){

	char buffer[20];

	int stdInput = read(0, buffer, 20);

	int fd = open("test11.txt", O_WRONLY);

	if(fd < 0){
		printf("Error occurred while opening the file");
	}

	int copy_fd = dup(fd);

	int copy_dup2_fd = dup2(fd , 1);

	int fd_fcntl = fcntl(fd , F_DUPFD);

	if(fd_fcntl == -1){
		printf("Error occurred while fetching fcntl");
	}

	printf("opnned fcntl , %d" , fd_fcntl);

	// printf("%d" , copy_fd);

	write(copy_fd , &buffer , 20);

	// fflush(stdin);

	write(copy_dup2_fd , &buffer , 20);

	write(fd_fcntl , &buffer , 20);

	write(fd , &buffer , 20);

	return 0;
}