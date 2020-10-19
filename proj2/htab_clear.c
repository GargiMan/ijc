// htab_clear.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// erase all items in table

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

void htab_clear(htab_t* t) {

    //check table pointer
    if (t == NULL) {
        fprintf(stderr, "Error : table does not exist\n");
        return;
    }

    //move to next index
    for (size_t i = 0; i < t->arr_size; i++) {

        //erase item and move to next one
        while (t->array[i] != NULL) {
            struct htab_item* item_next = t->array[i]->next;
            free(t->array[i]->key);
            free(t->array[i]);
            t->array[i] = item_next;
        }
    }

    //set number of items in table
    t->size = 0;

    return;
}
