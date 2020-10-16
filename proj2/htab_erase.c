// htab_erase.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// erase item from table selected by iterator

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_structs.h"

void htab_erase(htab_t * t, htab_iterator_t it) {

    //check table and iterator pointer
    if (t == NULL || !htab_iterator_valid(it)) {
        fprintf(stderr, "Error : table or iterator does not exist\n");
        return;
    }

    //first item at index will be erased
    if (t->array[it.idx] == it.ptr) {

        //change pointer at index
        t->array[it.idx] = it.ptr->next;

    } else { 
        
        //find previous iterator
        htab_iterator_t it_prev = {t->array[it.idx], t, it.idx};
        while (it_prev.ptr->next != it.ptr) it_prev.ptr = it_prev.ptr->next;
        it_prev.ptr->next = it.ptr->next;
    }

    //erase item and key
    free(it.ptr->key);
    free(it.ptr);
    t->size--;

    return;
}