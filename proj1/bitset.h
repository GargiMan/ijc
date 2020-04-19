// bitset.h
// Řešení IJC-DU1, příklad A), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// pole bitov definovane pomocou makro a inline funkcii

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"

typedef unsigned long* bitset_t;

typedef unsigned long bitset_index_t;

#define BITUL_SIZE (CHAR_BIT*sizeof(bitset_index_t))                                              //velkost unsigned long v bitoch

#define ARRAY_SIZE(size) ((size%BITUL_SIZE != 0 ? (size/BITUL_SIZE)+1 : (size/BITUL_SIZE)) +1)    //vypocet velkosti pola

#define bitset_create(jmeno_pole,velikost)\
bitset_index_t jmeno_pole[ARRAY_SIZE(velikost)];\
static_assert(velikost > 0,"Velkost pola musi byt vacsia ako 0!");\
jmeno_pole[0] = velikost;\
for (bitset_index_t i = 1;i < ARRAY_SIZE(velikost);i++) jmeno_pole[i] = 0;

#define bitset_alloc(jmeno_pole,velikost)\
bitset_t jmeno_pole = calloc(ARRAY_SIZE(velikost));\
if (jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace pameti\n");\
assert(velikost <= 500000000 && velikost > 0);\
jmeno_pole[0] = velikost;

#define bitset_free(jmeno_pole) free(jmeno_pole);

#ifndef USE_INLINE        //pouzije makro funkcie

  #define bitset_size(jmeno_pole) jmeno_pole[0]

  #define bitset_setbit(jmeno_pole,index,vyraz)\
  if (index+1 > bitset_size(jmeno_pole)+1) error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (bitset_index_t)index, (bitset_index_t)bitset_size(jmeno_pole));\
  (vyraz != 0 ? (jmeno_pole[(index / BITUL_SIZE)+1] = (jmeno_pole[(index / BITUL_SIZE)+1]) | (1UL << (index%BITUL_SIZE)))\
  : (jmeno_pole[(index / BITUL_SIZE)+1] = (jmeno_pole[(index / BITUL_SIZE)+1]) & (~(1UL << (index%BITUL_SIZE)))));

  #define bitset_getbit(jmeno_pole,index)\
  ((index+1 > bitset_size(jmeno_pole)+1) ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (bitset_index_t)index, (bitset_index_t)bitset_size(jmeno_pole)),0\
  : ((jmeno_pole[(index / BITUL_SIZE)+1] & (1UL << (index%BITUL_SIZE))) >> (index%BITUL_SIZE)))

#else                     //pouzije inline funkcie

  static inline bitset_index_t bitset_size(bitset_t jmeno_pole) {
    return jmeno_pole[0];
  }

  static inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, bitset_index_t vyraz) {
    if (index > bitset_size(jmeno_pole)) {
      error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole));
    } else if (vyraz != 0) {
      jmeno_pole[(index / BITUL_SIZE)+1] = ((jmeno_pole[(index / BITUL_SIZE)+1]) | (1UL << (index%BITUL_SIZE)));
    } else {
      jmeno_pole[(index / BITUL_SIZE)+1] = ((jmeno_pole[(index / BITUL_SIZE)+1]) & (~(1UL << (index%BITUL_SIZE)))); 
    }

  }

  static inline bitset_index_t bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
    if (index > bitset_size(jmeno_pole)) {
      error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole));
    }
      
    return (jmeno_pole[(index / BITUL_SIZE)+1] & (1UL << (index%BITUL_SIZE))) >> (index%BITUL_SIZE);

  }
  
#endif