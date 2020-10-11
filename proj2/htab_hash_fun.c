// htab_hash_func.c
// Řešení IJC-DU2, příklad B), 22.4.2020
// Autor: 
// Přeloženo: gcc 7.5.0
// hash function

#include <stdint.h> //uint32_t
#include "htab.h"

size_t htab_hash_fun(const char* str) {

    uint32_t h = 0;     // must be 32bit int
    const unsigned char* p;

    for (p = (const unsigned char*)str; *p != '\0'; p++) h = 65599 * h + *p;

    return h;
}