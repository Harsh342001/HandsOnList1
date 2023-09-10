/*
============================================================================
Name : 4.c
Author : Harsh Ranpariya
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th Aug, 2023.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    int fd = open("/home/harsh/sslab/hl3.txt", O_RDONLY | O_CREAT );
  
    printf("fd = %d\n", fd);
  
    if (fd == -1) {
        perror("Error occured while opening file");
    }
    return 0;
}