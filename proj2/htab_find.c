// htab_find.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// search for item with key

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key) {

    //check table pointer
    if (t == NULL) return htab_end(t);

    size_t index = htab_hash_function(key) % t->arr_size;

    htab_iterator_t it_found = {t->array[index], t, index};

    return it_found;
}

// ZLE ? 