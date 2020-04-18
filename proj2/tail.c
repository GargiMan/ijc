#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define LINELIMIT 1025 //1023+2 (\0 and \n)

// error exit function
void error_exit(const char *fmt, ...);

// warning msg function
void warning_msg(const char *fmt, ...);

// tail function
int main(int argc, char* argv[]) {

    //variables for -n argument
    unsigned long nlines = 10;      //number of lines to print, default - 10
    bool invert = 0;                //invert to print from bottom or top

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

    //variable set
    bool fread = 0;                 //dont ignore stdin until checked for files in arguments
    char readline[LINELIMIT] = "";       //last read line
    unsigned long rlines = 0;       //number of lines read
    bool errorprinted = 0;          //prints only once error for too long lines
    
    //search for all filenames
    for (int i = 1;i < argc;i++) {

        //skip -n argument
        if (strcmp(argv[i],"-n") == 0 ) {
            i++;
            continue;
        }

        //open and check file
        FILE* file = fopen(argv[i], "r"); 
        if (file == NULL) error_exit("cannot open \'%s\' for reading: No such file or directory\n", argv[i]);
        
        //ignore stdin
        fread = 1;
        
        //read and count lines
        while(fgets(readline,LINELIMIT,file) != NULL) rlines++;
        fclose(file);

        //reopen file and print lines
        fopen(argv[i], "r");
        for (unsigned long i = 0; i < rlines; i++) {
            fgets(readline,LINELIMIT,file);
            if (i >= (invert ? nlines-1 : rlines-nlines)) fprintf(stdout,"%s",readline);
            if (readline[strlen(readline)-1] != '\n' && strlen(readline) == 1025 && errorprinted == 0) {
                errorprinted = 1;
                warning_msg("numbers of chars on single line exceeded limit %lu chars (including \\0 and \\n)\n",LINELIMIT);
            }
            if (readline[strlen(readline)-1] != '\n') fprintf(stdout,"\n"); 
        }
        fclose(file);
    }

    //read stdin only if file was not passed in arguments
    if (fread == 0) {
        
        char* line[nlines];

        for (unsigned long i = 0; i < nlines; i++) {
            line[i] = malloc(LINELIMIT*sizeof(char));
            if (line[i] == NULL) error_exit("allocation for \'%lu\' lines failed\n",nlines); 
        }

        for (rlines = 0;*(fgets(readline,LINELIMIT,stdin)) != EOF;rlines++) {
            for (unsigned long j = 0; j < nlines-1; j++) line[j] = line[j+1];
            line[nlines-1]=readline;
            if (readline[strlen(readline)-1] != '\n' && strlen(readline) == 1025 && errorprinted == 0) {
                errorprinted = 1;
                warning_msg("numbers of chars on single line exceeded limit %lu chars (including \\0 and \\n)\n",LINELIMIT);
            }
        }

        for (unsigned long i = 0; i < nlines; i++) {
            fprintf(stdout,"%s",line[i]);
            if (line[i][strlen(readline)-1] != '\n') fprintf(stdout,"\n");  
            free(line[i]);
        }
    }

    return 0;
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


// výpis 1x na stderr o prekročení limitu riadku 

// malloc in stdin