// htab_clear.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vymaze vsetky prvky tabulky

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

void htab_clear(htab_t * t) {

    if (t == NULL)
        return;

    for (size_t i = 0; i < t->arr_size; i++) {
        
        for (struct htab_item *nextitem; t->array[i] != NULL; t->array[i] = nextitem) {

            nextitem = t->array[i]->next;
            free(t->array[i]->key);
            free(t->array[i]);
        }
    }

    return;
}