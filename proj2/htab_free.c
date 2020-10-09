// htab_free.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vymaze vsetky prvky tabulky a zmaze tabulku

#include <stdlib.h>
#include "htab.h"

void htab_free(htab_t * t) {
    
    htab_clear(t);
    free(t);
    
    return;
}