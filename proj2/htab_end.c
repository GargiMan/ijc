// htab_end.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// return iterator behind last item

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_end(const htab_t * t) {

    //new iterator for return
    htab_iterator_t it_end = {NULL, t, 0};

    //check table pointer
    if (t == NULL) return it_end;

    //set index after table pointer check
    it_end.idx = t->arr_size - 1;

    //search for last index with item
    while (it_end.idx > 0 && t->array[it_end.idx] == NULL) it_end.idx--;

    //not last index is end or first is end
    if ((it_end.idx > 0 && it_end.idx < t->arr_size - 1) || (it_end.idx == 0 && t->array[it_end.idx] != NULL)) it_end.idx++;

    return it_end;
}