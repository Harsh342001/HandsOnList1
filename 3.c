#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    int fd = creat("/home/harsh/sslab/hl3.txt", 0777);
  
    printf("fd = %d\n", fd);
  
    if (fd == -1) {
      perror("Error occured while creating file");
    }
    return 0;
}
