// htab_iterator_set_value.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// set iterator (item) value and return it

#include "htab.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {

    //set iterator (item) value and return it
    return it->ptr->data = val;
}