#include <sys/types.h>
#include <stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>

int main(){
	
	char buffer[20];

	int inputRead = read(0, buffer, 20);
	int OutputWritten = write(1,buffer,20);

	if(inputRead == -1 && OutputWritten == -1){
		printf("Error");
	}
	return 0;
}