// htab_begin.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// return iterator with first item in table

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_begin(const htab_t * t) {

    //new iterator for return
    htab_iterator_t it_begin = {NULL, t, 0};

    //check table pointer
    if (t == NULL) {
        fprintf(stderr, "Error : table does not exist\n");
        return it_begin;
    }

    //search for first index with item
    while (it_begin.idx < t->arr_size && t->array[it_begin.idx] == NULL) it_begin.idx++;

    //empty table
    if (it_begin.idx == t->arr_size) it_begin.idx = 0;

    //set pointer with index
    it_begin.ptr = t->array[it_begin.idx];

    return it_begin;
}