// htab_free.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// erase all items and table

#include <stdlib.h>
#include "htab.h"

void htab_free(htab_t * t) {
    
    //erase all items
    htab_clear(t);

    //erase table
    free(t);
    
    return;
}