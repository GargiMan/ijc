// tail.c
// Řešení IJC-DU2, příklad A), 19.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// like posix tail , print last n(10) lines from stdin (or file)

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define LINELIMIT 1024                  //1023+1 , limit for number of char in single line

void readnprint(FILE *stream, unsigned long nlines, bool invert);
void error_exit(const char *fmt, ...);
void warning_msg(const char *fmt, ...);

// tail function
int main(int argc, char *argv[]) {

    //variables for lines to print
    bool invert = 1;                    //invert to print from bottom or top
    unsigned long nlines = 10;          //number of lines to print, default - 10

    //parse arguments
    for (int i = 1;i < argc;i++) {

        //print usage manual
        if (strcmp(argv[i],"--help") == 0) {

            printf("Usage: ./tail [OPTION]... [FILE]...\n\n");
            printf("Print the last 10 lines of each FILE to standard output.\n");
            printf("With no FILE, read standart input.\n");
            printf("Lines are limited to %d characters.\n\n",LINELIMIT-1);
            printf("Options:\n");
            printf("\t-n NUM\t\toutput the last NUM lines, instead of the last 10,\n");
            printf("\t\t\t  use -n +NUM to output starting with line NUM,\n");
            printf("\t\t\t  NUM can be in octal (0...), hexadecimal (0x...) or decimal form\n");
            printf("\t--help\t\tdisplay this help and exit\n");

            return 0;
        }

        //change number of lines to be printed
        if (strcmp(argv[i],"-n") == 0 ) {
            if (argc > ++i) {

                //convert argument into ulong value
                char* ptr;
                nlines = strtoul(argv[i], &ptr ,0);

                if (strcmp(ptr,"") != 0) 
                    error_exit("argument \'%s\' is not correct numeric value\nUse --help option for info\n", argv[i]);

                //invert line read
                if (argv[i][0] == 43) 
                    invert = !invert;

                //check -n argument value
                if (argv[i][0] == 45 || nlines == ULONG_MAX)
                    error_exit("argument \'%s\' must be more than 0 and less than %lu (unsgined long)\nUse --help option for info\n", argv[i], ULONG_MAX);
                
            //argument -n without value
            } else {
                error_exit("argument \'-n\' needs to be followed by number\nUse --help option for info\n");
            }
        }
    }

    //0 lines to print from back , return 0
    if (nlines == 0 && invert) 
        return 0;

    bool fread = 0;         // if any of arguments is valid file, othewise read stdin   

    //search for files in arguments
    for (int i = 1;i < argc;i++) {

        //skip -n argument and value
        if (strcmp(argv[i],"-n") == 0 ) {
            i++;
            continue;
        }

        //open and check file
        FILE* file = fopen(argv[i], "r"); 
        if (file == NULL)
            error_exit("cannot open \'%s\' for reading: No such file or directory\nUse --help option for info\n", argv[i]);

        //ignore stdin
        fread = 1;

        //read file, print and close
        readnprint(file,nlines,invert);
        fclose(file);
    }

    //read stdin
    if (fread == 0) readnprint(stdin,nlines,invert);

    return 0;
}

// read and print algorythm function
void readnprint(FILE* stream, unsigned long nlines, bool invert) {

    //variable set
    bool warningprinted = 1;            //prints only once error for too long lines
    char rline[LINELIMIT];              //last read line
    unsigned long rlines = 0;           //number of lines read 

    //non inverted print
    if (invert) {

        //line array variable
        char* line[nlines];

        //alloc array for lines
        for (unsigned long i = 0; i < nlines; i++) {
            line[i] = calloc(LINELIMIT,sizeof(char));
            if (line[i] == NULL) 
                error_exit("allocation for %lu lines failed\n",nlines); 
        }

        //read and save
        while(fgets(rline,LINELIMIT,stream) != NULL) {

            //move lines in array and save new
            for (unsigned long j = 0; j < nlines-1; j++) 
                sprintf(line[j],"%s",line[j+1]);

            sprintf(line[nlines-1],"%s",rline);
            
            //if line is not ended with \n and is full of chars
            if (strchr(rline,'\n') == NULL && strlen(rline) == LINELIMIT-1) {

                //warning once line exceeded limit
                if (warningprinted) {
                    warningprinted = 0;
                    warning_msg("numbers of chars on single line exceeded limit %lu chars\n",LINELIMIT);
                }

                //skip the rest of line
                while (fgets(rline,LINELIMIT,stream) != NULL) 
                    if (strchr(rline,'\n') != NULL) 
                        break; 
            }
        }

        //print and free array
        for (unsigned long i = 0; i < nlines; i++) {

            if (strlen(line[i]) == 0) 
                continue;

            fprintf(stdout,"%s",line[i]);
            if (strchr(line[i],'\n') == NULL) 
                fprintf(stdout,"\n");

            free(line[i]);
        }

    //inverted print
    } else {
        for (rlines = 1;fgets(rline,LINELIMIT,stream) != NULL;rlines++) {
            
            //warning once line exceeded limit
            if (strchr(rline,'\n') == NULL && strlen(rline) == LINELIMIT-1) {

                if (warningprinted) {
                    warningprinted = 0;
                    warning_msg("numbers of chars on single line exceeded limit %lu chars\n",LINELIMIT);
                }

                //read until EOF or \n
                char tmp[LINELIMIT];
                while (fgets(tmp,LINELIMIT,stream) != NULL) 
                    if (strchr(tmp,'\n') != NULL) 
                        break;
            }

            //print
            if (rlines >= nlines) {
                fprintf(stdout,"%s",rline);
                if (strchr(rline,'\n') == NULL) 
                    fprintf(stdout,"\n");
            }
        }
    }
}

//error exit function created in DU1
void error_exit(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "Error : ");
    vfprintf(stderr, fmt, args);
    va_end (args);
    exit(1);
}

//warning msg function created in DU1
void warning_msg(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "Warning : ");
    vfprintf(stderr, fmt, args);
    va_end (args);
}