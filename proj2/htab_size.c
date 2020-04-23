// htab_size.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vrati pocet prvkov tabulky

#include "htab.h"
#include "htab_structs.h"

size_t htab_size(const htab_t * t) {

    if (t == NULL)
        return 0;

    return t->size;
}