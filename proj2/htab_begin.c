// htab_begin.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// nastavi iterator na zaciatok tabulky

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_begin(const htab_t * t) {

    htab_iterator_t it_begin = {NULL,NULL,0};

    if (t == NULL) return it_begin;
    it_begin.t = t;

    for (size_t i = 0; i < t->arr_size; i++) {
        
        it_begin.ptr = t->array[i];

        if (it_begin.ptr != NULL) {
            it_begin.idx = i;
            break; 
        }
    }

    return it_begin;
}