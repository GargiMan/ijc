// steg-decode.c
// Řešení IJC-DU1, příklad B), 8.8.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// zakoduje spravu do dat ppm suboru

#include <string.h>
#include <stdio.h>
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 5 || strcmp(argv[1],"--help") == 0) 
        error_exit("Incorrect number of arguments, usage:\n./steg-decode [FILE] [-o FILE_OUT] [-m MESSAGE]\nRead data from FILE , encode MESSAGE and write back into FILE\n");
        //-o FILE  changes output file , If FILE_OUT doesn't exist, new one will be created in program directory\n
        //If arguments don't contain MESSAGE , it will be read from standart input\n

    struct ppm *img = ppm_read(argv[1]);
    if (img == NULL) 
        error_exit("%s : File couldn't be loaded\n", argv[1]);

    unsigned long imgsize = (img->xsize)*(img->ysize)*3;

    bitset_alloc(pole, imgsize);
    Eratosthenes(pole);


        for (int i = 1;i < argc;i++) {}



    bitset_free(pole);
    ppm_free(img);

    return 0;
}