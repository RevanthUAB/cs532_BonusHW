#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/wait.h>

int autocalcnum_myshell();

int file_Discriptor,input_fd,output_fd;

int hello_myshell(char **inputs_myshell);
int fibonacci_myshell(char **inputs_myshell);
int list_myshell(char **inputs_myshell);
int cd_myshell(char **inputs_myshell);
int help_myshell(char **inputs_myshell);
int quit_myshell(char **inputs_myshell);
int history_myshell(char **inputs_myshell);

char *cmdarray_myshell[];
int (*functions_myshell[]) (char **);

char *readingInput_myshell(void);


char **tokenLine_myshell(char *myshell_readline);

int execvpCall_myshell(char **inputs_myshell);
int run_myshell(char **inputs_myshell);


#endif