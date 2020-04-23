// htab_lookup_add.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vyhlada zaznam podlka kluca a prida zaznam

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key) {

    if (t == NULL || key == NULL) {
        fprintf(stderr, "Error : table of key does not exist\n");
        return htab_end(t);
    }

    size_t index = htab_hash_function(key) % t->arr_size;

    htab_iterator_t it_found = {t->array[index], t, index};

    while(htab_iterator_valid(it_found) && it_found.idx == index) {
        if (strcmp(htab_iterator_get_key(it_found), key) == 0)
            return it_found;

        it_found = htab_iterator_next(it_found);
    }

    it_found.ptr = mallloc(sizeof(struct htab_item));
    if (it_found.ptr == NULL) {
        fprintf(stderr, "Error : allocation for new item failed\n");
        return htab_end(t);
    }

    it_found.ptr->key = malloc(strlen(key) + 1);

    if (htab_iterator_get_key(it_found) == NULL) {
        free(it_found.ptr);
        return htab_end(t);
    }

    sprintf(it_found.ptr->key,"%s",key);
    htab_iterator_set_value(it_found, 0);
    
    it_found.ptr->next = t->array[index];
    t->array[index] = it_found.ptr;
    t->size++;

    return it_found;
}