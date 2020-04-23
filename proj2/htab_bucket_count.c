// htab_bucket_count.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vrati velkost tabulky

#include "htab.h"
#include "htab_structs.h"

size_t htab_bucket_count(const htab_t * t) {

    if (t == NULL)
        return 0;

    return t->arr_size;

}