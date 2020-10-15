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
    if (t == NULL || key == NULL) {
        fprintf(stderr, "Error : table does not exist or key is empty\n");
        return htab_end(t);
    }

    //index calculation for key
    size_t index = htab_hash_function(key) % t->arr_size;

    //new iterator for return
    htab_iterator_t it_found = {t->array[index], t, index};

    //search for key
    while(htab_iterator_valid(it_found) && it_found.idx == index) {
        if (strcmp(htab_iterator_get_key(it_found), key) == 0) return it_found;
        it_found = htab_iterator_next(it_found);
    }

    return it_found;
}