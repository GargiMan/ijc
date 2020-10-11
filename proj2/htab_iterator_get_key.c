// htab_iterator_get_key.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// return key from iterator

#include "htab.h"

htab_key_t htab_iterator_get_key(htab_iterator_t it) {

    //return key from iterator
    return it->ptr->key;
}
