// htab_erase.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// erase item from table selected by iterator

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

void htab_erase(htab_t * t, htab_iterator_t it) {

    //check table and iterator pointer
    if (t == NULL || it->ptr == NULL) return;

    //erase item
    for (size_t i = 0; i < t->arr_size; i++) {
        for (struct htab_item *item = t->array[i]; item != NULL; item = item->next) {

            if ( it->ptr == item) {

                    //not finished yet

                return;
            }
        }
    }

    return;
}