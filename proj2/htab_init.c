// htab_init.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vrati velkost tabulky

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_structs.h"

htab_t *htab_init(size_t n) {

    if (n == 0) {
        fprintf(stderr,"Error : size of table need to be bigger than 0\n");
        return NULL;
    }

    //                   velkost struktury  velkost 1 zaznamu * pocet vsetkych   
    htab_t *table = malloc(sizeof(htab_t) + sizeof(struct htab_item *) * n); 

    if (table == NULL) {
        fprintf(stderr,"Error : table allocation failed\n");
        return NULL;
    }

    table->size=0;
    table->arr_size = n;

    for (size_t i = 0; i < n; i++)
        table->array[i] = NULL;

    return table;
}