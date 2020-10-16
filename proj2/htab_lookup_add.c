// htab_lookup_add.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// search for item with key, if doesn't exist, create new

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key) {

    //check table pointer
    if (t == NULL || key == NULL) {
        fprintf(stderr, "Error : table does not exist or key is empty\n");
        return htab_end(t);
    }

    //index calculation for key
    size_t index = htab_hash_fun(key) % t->arr_size;

    //new iterator for return
    htab_iterator_t it_found = {t->array[index], t, index};

    //search for key
    while(htab_iterator_valid(it_found) && it_found.idx == index) {
        if (strcmp(htab_iterator_get_key(it_found), key) == 0) return it_found;
        it_found = htab_iterator_next(it_found);
    }

    //item allocation and check pointer
    it_found.ptr = malloc(sizeof(struct htab_item));
    if (it_found.ptr == NULL) {
        fprintf(stderr, "Error : allocation for new item failed\n");
        return htab_end(t);
    }

    //key allocation and check pointer
    it_found.ptr->key = malloc(strlen(key) + 1);
    if (htab_iterator_get_key(it_found) == NULL) {
        free(it_found.ptr);
        fprintf(stderr, "Error : allocation for new item key failed\n");
        return htab_end(t);
    }

    //set key and value for item
    sprintf(it_found.ptr->key,"%s",key);    //set key
    htab_iterator_set_value(it_found, 0);
    
    //add new item in table
    it_found.ptr->next = t->array[index];
    t->array[index] = it_found.ptr;
    t->size++;

    return it_found;
}