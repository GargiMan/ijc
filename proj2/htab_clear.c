// htab_clear.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vymaze vsetky prvky tabulky

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

void htab_clear(htab_t* t) {

    if (t == NULL) return;

    for (size_t i = 0; i < t->arr_size; i++) {

        struct htab_item* next_item;

        while (t->array[i] != NULL) {

            next_item = t->array[i]->next;
            free(t->array[i]->key);
            free(t->array[i]);
            t->array[i] = next_item;
        }
    }

    t->size = 0;

    return;
}
