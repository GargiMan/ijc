// htab_structs.h
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// skryte struktury hash tabulky

#ifndef __HTAB_STRUCTS_H__
#define __HTAB_STRUCTS_H__

#include "htab.h"

struct htab {
    size_t size;                    //aktualny pocet zaznamov [key,data,next]
    size_t arr_size;                //velkost nasledujuceho pola ukazatelov
    struct htab_item *array[];      //pole ukazatelov
};

struct htab_item {
    char *key;                      //hash kluc prvku
    int data;                       //hodnota(obsah) prvku
    struct htab_item *next;         //ukazatel na dalsi prvok
};

#endif // __HTAB_STRUCTS_H__