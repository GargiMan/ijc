// htab_init.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// initialize table with n size of array

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_t* htab_init(size_t n) {

    //check table size
    if (n == 0) {
        fprintf(stderr,"Error : size of table expected to be bigger than 0\n");
        return NULL;
    }

    //table allocation = table struct + item struct pointer * array size
    htab_t* tab = malloc(sizeof(htab_t) + sizeof(struct htab_item*) * n); 
    if (tab == NULL) {
        fprintf(stderr,"Error : table allocation failed\n");
        return NULL;
    }

    //set table array size and number of items
    tab->size = 0;
    tab->arr_size = n;

    //set all item pointers to NULL
    for (size_t i = 0; i < n; i++) tab->array[i] = NULL;

    return tab;
}