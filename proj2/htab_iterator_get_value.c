// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vrati hodnotu iteratoru

#include <stdlib.h>
#include <assert.h>
#include "htab.h"
#include "htab_structs.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {

    assert(htab_iterator_valid(it));

    return it.ptr->data;