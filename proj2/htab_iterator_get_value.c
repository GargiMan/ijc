// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vrati hodnotu zaznamu (iteratoru)

#include "htab.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {

    return it->ptr->data;