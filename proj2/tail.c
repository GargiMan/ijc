#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define LINELIMIT 1024                  //1023+1 , limit for number of char in single line

void readnprint(FILE* stream, unsigned long numoflines, bool invertprint);
void error_exit(const char *fmt, ...);
void warning_msg(const char *fmt, ...);

// tail function
int main(int argc, char* argv[]) {

    //variables for -n argument
    bool invert = 0;                    //invert to print from bottom or top
    unsigned long nlines = 10;          //number of lines to print, default - 10

    //search for last -n argument
    for (int i = 1;i < argc;i++) {

        //check if argument is -n and if its followed by value
        if (strcmp(argv[i],"-n") == 0 ) {
            if (argc > ++i) {
                
                //convert argument into ulong value
                char* ptr;
                nlines = strtoul(argv[i], &ptr ,0);
                if (argv[i][0] == 43) invert = !invert;

                //check -n argument value
                if (strcmp(ptr,"") != 0) error_exit("argument \'%s\' is not correct decimal value \n", argv[i]);
                if (argv[i][0] == 45 || nlines == ULONG_MAX) error_exit("argument \'%s\' must be more than 0 and less than %lu (unsgined long) \n", argv[i], ULONG_MAX);

            //argument -n without value
            } else {
                error_exit("argument \'-n\' needs to be followed by number\n");
            }
        }
    }

    //0 lines to print from back , return 0
    if (nlines == 0 && invert == 0) return 0;

    //variable set
    bool fread = 0;                     //dont ignore stdin until checked for files in arguments

    //search for files in arguments
    for (int i = 1;i < argc;i++) {

        //skip -n argument and value
        if (strcmp(argv[i],"-n") == 0 ) {
            i++;
            continue;
        }

        //open and check file
        FILE* file = fopen(argv[i], "r"); 
        if (file == NULL) error_exit("cannot open \'%s\' for reading: No such file or directory\n", argv[i]);
        
        //ignore stdin
        fread = 1;

        //read file and print 
        readnprint(file,nlines,invert);

        //close file
        fclose(file);
    }

    //read stdin only if file was not passed in arguments
    if (fread == 0) readnprint(stdin,nlines,invert);

    return 0;
}


// read and print algorythm function
void readnprint(FILE* stream, unsigned long numoflines, bool invertprint) {

    //variable set
    bool warningprinted = 0;            //prints only once error for too long lines
    char readline[LINELIMIT];           //last read line
    unsigned long rlines = 0;           //number of lines read 

    //non inverted print
    if (invertprint == 0) {

        //line array variable
        char* line[numoflines];

        //alloc array for lines
        for (unsigned long i = 0; i < numoflines; i++) {
            line[i] = calloc(LINELIMIT,sizeof(char));
            if (line[i] == NULL) error_exit("allocation for %lu lines failed\n",numoflines); 
        }

        //read and save
        while(fgets(readline,LINELIMIT,stream) != NULL) {

            //move lines in array and save new
            for (unsigned long j = 0; j < numoflines-1; j++) sprintf(line[j],"%s",line[j+1]);
            sprintf(line[numoflines-1],"%s",readline);
            
            //if line is not ended with \n and is full of chars
            if (strchr(readline,'\n') == NULL && strlen(readline) == LINELIMIT-1) {

                //warning once line exceeded limit
                if (warningprinted == 0) {
                    warningprinted = 1;
                    warning_msg("numbers of chars on single line exceeded limit %lu chars\n",LINELIMIT);
                }

                //skip the rest of line
                while (fgets(readline,LINELIMIT,stream) != NULL) if (strchr(readline,'\n') != NULL) break; 
            }
        }

        //print and free array
        for (unsigned long i = 0; i < numoflines; i++) {
            if (strlen(line[i]) == 0) continue;
            fprintf(stdout,"%s",line[i]);
            if (strchr(line[i],'\n') == NULL) fprintf(stdout,"\n");
            free(line[i]);
        }

    //inverted print
    } else {
        for (rlines = 1;fgets(readline,LINELIMIT,stream) != NULL;rlines++) {
            
            //warning once line exceeded limit
            if (strchr(readline,'\n') == NULL && strlen(readline) == LINELIMIT-1) {
                if (warningprinted == 0) {
                    warningprinted = 1;
                    warning_msg("numbers of chars on single line exceeded limit %lu chars\n",LINELIMIT);
                }

                //read until EOF or \n
                char tmp[LINELIMIT];
                while (fgets(tmp,LINELIMIT,stream) != NULL) if (strchr(tmp,'\n') != NULL) break;
            }

            if (rlines >= numoflines) {
                fprintf(stdout,"%s",readline);
                if (strchr(readline,'\n') == NULL) fprintf(stdout,"\n");
            }
        }
    }
}


//error exit function created in DU1
void error_exit(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "Error (tail) : ");
    vfprintf(stderr, fmt, args);
    va_end (args);
    exit(1);
}


//warning msg function created in DU1
void warning_msg(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "Warning (tail) : ");
    vfprintf(stderr, fmt, args);
    va_end (args);
}

//vytvorit chybove hlasenia ?