/*
============================================================================
Name : 13.c
Author : Harsh Ranpariya
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
                  verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

 int main(void)
       {
           int  retval;
           fd_set rfds;
           struct timeval  tv;

           FD_ZERO(&rfds);
           FD_SET(0, &rfds);

           /* Wait up to five seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;

           retval = select(1, &rfds, NULL, NULL, &tv);

           if (retval == -1)
               perror("select()");
           else if (retval)
               printf("Data is available now.\n");
           else
               printf("No data within five seconds.\n");

           return 0;

       }
