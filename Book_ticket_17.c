/*
============================================================================
Name : Book_ticket_17.c
Author : Harsh Ranpariya
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
                Write a program to open a file, store a ticket number and exit. Write a separate program, to
                open the file, implement write lock, read the ticket number, increment the number and print
                the new ticket number then close the file.
Date: 28th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    struct{
        int tic_no;
    }ticket;
  
    struct flock lock;
    
    int fd = open("ticket.txt",O_RDWR);
   
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();
    printf("Before Entering Into Critical Section\n");
    
    //set the write lock using F_SETLKW
    fcntl(fd,F_SETLKW,&lock);
    printf("lock applied successfully");
    read(fd,&ticket,sizeof(ticket));
    printf("ticket no : %d\n",ticket.tic_no);
    
    //updating the value of tickets
    ticket.tic_no++;
    
    lseek(fd,0,SEEK_SET);
    write(fd,&ticket,sizeof(ticket));
    //set the current pointer 
    printf("entered critical section\n");
    printf("press key to unlock : ");
    getchar();
    lock.l_type = F_UNLCK;
    printf("unlocked\n");
    fcntl(fd,F_SETLK,&lock);
    printf("done\n");
    return 0;
}
