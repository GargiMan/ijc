// htab_find.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vyhlada zaznam podla kluca

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key) {

    if (t == NULL || key == NULL) {
        fprintf(stderr, "Error : tabulka alebo kluc neexistuje\n");
        return htab_end(t);
    }

    size_t index = htab_hash_function(key) % t->arr_size;

    htab_iterator_t it_found = {t->array[index], t, index};

    return it_found;
}