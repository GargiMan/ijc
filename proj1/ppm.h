// ppm.h
// Řešení IJC-DU1, příklad B), 18.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// hlavicka suboru ppm.c

#define IMG_SIZE_LIMIT (8000*8000*3)

struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);