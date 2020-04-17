#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// error exit function
void error_exit(const char *fmt, ...);

// tail function
int main(int argc, char* argv[]) {

    //variables for -n argument
    unsigned long nlines = 10;
    bool invert = 0;

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
                if (strcmp(ptr,"") != 0) error_exit("Argument \'%s\' is not correct decimal value \n", argv[i]);
                if (argv[i][0] == 45 || nlines == ULONG_MAX) error_exit("Argument \'%s\' must be more than 0 and less than %lu (unsgined long) \n", argv[i], ULONG_MAX);

            //argument -n without value
            } else {
                error_exit("Argument \'-n\' needs to be followed by number\n");
            }
        }
    }

    //variable for stdin read and print
    bool fread = 0;
    
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
        
        //set variables
        fread = 1;
        char lastline[1025];
        unsigned long flines = 0;
        
        //read and count lines
        while(fgets(lastline,1025,file) != NULL) flines++;
        fclose(file);

        //reopen file and print lines
        fopen(argv[i], "r");
        for (unsigned long i = 0; i < flines; i++) {
            fgets(lastline,1025,file);
            if (i >= (invert ? nlines-1 : flines-nlines)) printf("%s",lastline);
            if (strchr(lastline,'\n') == NULL) printf("\n"); 
        }
        fclose(file);
    }

    //read stdin only if file was not passed in arguments
    if (fread == 0) {
        //fgets(lastline,1025,stdin);
    }

    return 0;
}

//error exit function created in DU1
void error_exit(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "tail: ");
    vfprintf(stderr, fmt, args);
    va_end (args);
    exit(1);
}




// výpis 1x na stderr o prekročení limitu riadku 

// malloc in stdin