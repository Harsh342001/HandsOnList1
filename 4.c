#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    int fd = open("/home/harsh/sslab/hl3.txt", O_RDONLY | O_CREAT | O_EXCL);
  
    printf("fd = %d\n", fd);
  
    if (fd == -1) {
        perror("Error occured while opening file");
    }
    return 0;
}