/*
============================================================================
Name : 8.c
Author : Harsh Ranpariya
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        perror("Error : missing arguements");
        return 1;
    }

    int fileDescriptor = open(argv[1], O_RDONLY);

    if (fileDescriptor == -1) {
            perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    ssize_t bytesRead;

    char line[1024];
    int lineIndex = 0;

    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                write(STDOUT_FILENO, line, lineIndex);
                write(STDOUT_FILENO, "\n", 1);
                lineIndex = 0; 
            } else {
                line[lineIndex] = buffer[i];
                lineIndex++;
            }
        }
        sleep(5);
    }
    close(fileDescriptor);

    return 0;
}
