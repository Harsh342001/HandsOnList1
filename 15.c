/*
============================================================================
Name : 15.c
Author : Harsh Ranpariya
Description : 15. Write a program to display the environmental variable of the user (use environ).
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

    
int main(){
        extern char **environ;
        while(*environ){
                if(strncmp(*environ, "USER", 4)==0){
                        printf("%s\n",*environ);
                }
                environ++;
        }


}