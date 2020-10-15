// htab_hash_func.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// hash function

#include <stdint.h> //uint32_t
#include "htab.h"

size_t htab_hash_fun(const char* str) {

    //hash variables
    uint32_t h = 0;     // must be 32bit int
    const unsigned char* p;

    //hash index calculation
    for (p = (const unsigned char*)str; *p != '\0'; p++) h = 65599 * h + *p;

    return h;
}