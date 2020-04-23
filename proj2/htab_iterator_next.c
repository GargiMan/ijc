// htab_iterator_next.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// posunie iterator o 1 dalej

#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it) {

    if (htab_iterator_valid(it) == NULL)
        return it;

    //not finished yet

    return it;
}