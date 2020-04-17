// eratosthenes.c
// Řešení IJC-DU1, příklad A), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// oznacenie prvocisel hodnotou bitu 1

#include <math.h>
#include "eratosthenes.h"
#include "bitset.h"

void Eratosthenes(bitset_t pole) {

    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    for (bitset_index_t i = 2; i < sqrt(bitset_size(pole)); i++){
        if (bitset_getbit(pole, i) == 0) {
            for (bitset_index_t j = 2; i*j <= bitset_size(pole); j++) {
                bitset_setbit(pole, i*j, 1);
            }
        }
    }

}