#include <stdio.h>
#include <stdlib.h>

// This is a program to simulate the basic cat system call

// Algorithm:

// cat: open, reads, write, close.

// functions to use: fopen, fgets, fclose. (in c standerd liberary). 

// The user should write in terminal something such as ./wcat main.c
// The output will be main.c contents 

// 1- open the file using fopen(), read about it in them man page, if it succeded it will reutrn a file pointer, otherwise it reutrns null. 
// 2- if null => cannot open the file. 
// 3- if there is a fail use perror()..
// 4- once the file is opend read it using fgets() into a buffer variable (size is determined in the run time). 
// 5- printf the buffer to present the file content, with no /n to not change file content 
// 6- Use fclose() to close the file. 

// Notes, you can read one or more files. 
// in all non-error cases just use return 0
// when it's wcat: cannot open file" (followed by a newline) and exit with status code 1. 


int main(int argc, char *argv[]) {

    if (argc == 1) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buffer [100];

        while (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            printf("%s", buffer);
        }

            fclose(fp);

        
    }
            return 0;

}