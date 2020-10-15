// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// return value from iterator

#include "htab.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {

    //check iterator pointer
    if (!htab_iterator_valid(it)) {
        fprintf(stderr, "Error : iterator is incorrect\n");
        return NULL;
    }

    //return value from iterator
    return it->ptr->data;