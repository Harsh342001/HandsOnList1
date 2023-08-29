#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void) {
	int fd1 = open("hl51.txt" , O_RDWR | O_CREAT);
	int fd2 = open("hl52.txt" , O_RDWR | O_CREAT);
	int fd3 = open("hl53.txt" , O_RDWR | O_CREAT);
	int fd4 = open("hl54.txt" , O_RDWR | O_CREAT);
	int fd5 = open("hl55.txt" , O_RDWR | O_CREAT);

	for(;;);

}