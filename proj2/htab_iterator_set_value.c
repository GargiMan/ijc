// htab_iterator_set_value.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// nastavi obsah iteratoru na val

#include <stdlib.h>
#include <assert.h>
#include "htab.h"
#include "htab_structs.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {

    assert(htab_iterator_valid(it));

    return it.ptr->data = val;
}