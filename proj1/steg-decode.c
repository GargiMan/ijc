// steg-decode.c
// Řešení IJC-DU1, příklad B), 18.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// dekoduje spravu z dat ppm suboru

#include <stdio.h>
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"

int main(int argc, char *argv[]) {

    if (argc != 2) 
        error_exit("Incorrect number of arguments, usage:\n./steg-decode [FILE]\nDecode FILE and print message\n");

    struct ppm *img = ppm_read(argv[1]);
    if (img == NULL) 
        error_exit("%s : File couldn't be loaded\n", argv[1]);

    unsigned long imgsize = (img->xsize)*(img->ysize)*3;

    bitset_alloc(pole, imgsize);
	Eratosthenes(pole);

    char printc = '\0';
    int countc = 0;

    for (bitset_index_t i = 23;i < imgsize ;i++) {
        if (bitset_getbit(pole,i) == 0) {
            char tmp = img->data[i] & 1;
            tmp = tmp << countc;
            printc |= tmp;
            countc++;
            if (countc == CHAR_BIT) {
                fputc(printc,stdout);
                if (printc == '\0') break;
                countc = 0;
                printc = '\0';
            }
        }
    }

    fputc('\n',stdout);

    bitset_free(pole);
    ppm_free(img);
    
    return 0;
}