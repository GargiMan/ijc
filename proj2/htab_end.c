// htab_end.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// nastavi iterator za posledny zaznam v tabulke

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_end(const htab_t * t) {

    htab_iterator_t it_end = {NULL,NULL,0};

    if (t != NULL) {

        it_end.t = t;
        it_end.idx = t->arr_size - 1;

        for (size_t i = 0; i < t->arr_size; i++) {
            if (t->array[i] == NULL) {
                it_end.idx = i;
                break;
            }
        }
    }

    return it_end;
}