// htab_bucket_count.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// return size of table array

#include "htab.h"
#include "htab_structs.h"

size_t htab_bucket_count(const htab_t * t) {

    //check table pointer
    if (t == NULL) {
        fprintf(stderr, "Error : table does not exist\n");
        return;
    }

    //return size of table array
    return t->arr_size;

}