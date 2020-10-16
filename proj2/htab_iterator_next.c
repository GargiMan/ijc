// htab_iterator_next.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// move iterator to next item in table

#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it) {

    //check iterator pointer
    if (!htab_iterator_valid(it)) {
        fprintf(stderr, "Error : iterator is incorrect or at the end of table\n");
        return it;
    }

    //new iterator for return
    htab_iterator_t it_next = {NULL, it.t, it.idx};

    //not last item at index
    if (it.ptr->next != NULL) {
        
        //move to next item within same index
        it_next.ptr = it.ptr->next;

    //last at index
    } else {

        //move next index until next is not null
        while (it_next.ptr == NULL) {
            if (it_next.t->arr_size == ++it_next.idx) return htab_end(it_next.t);
            it_next.ptr = it_next.t->array[it_next.idx];
        }
    }

    return it_next;
}