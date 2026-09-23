#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algorithm 

// wgrep "pattern" file.txt 
// should read the file line by line then get the specified line. 
// it's case sensitive so foo is not Foo. 
// Use getline() to not get stuck with long lines. done 
//  If **wgrep** is passed no command-line arguments, it should print "wgrep: searchterm [file ...]\n"and exit with status 1. done 
// Cannot open the file => staus 1, "wgrep: cannot open file" done 
// Other success cases exit with 0
// searchTerm && !file read from read from standard input done 
// if passed empty string => can match no lines or all lines 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(FILE *input, char *pattern)
{
    char *line = NULL;
    size_t size = 0;

    while (getline(&line, &size, input) != -1) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    free(line);
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    // Search from standard input
    if (argc == 2) {
        search(stdin, argv[1]);
        return 0;
    }

    // Search through files
    for (int i = 2; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            return 1;
        }

        search(fp, argv[1]);

        fclose(fp);
    }

    return 0;
}