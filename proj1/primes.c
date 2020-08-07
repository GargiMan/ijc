// primes.c
// Řešení IJC-DU1, příklad A), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// vypocet casu za ktory sa vykona program , vyhladanie a vypis poslednych 10 prvocisel

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define N 5000000       //maximalna velkost prvocisla
#define X 10            //pocet cisiel ktore sa maju vypisat

int main(void){

    clock_t start = clock();

	bitset_create(pole,N);
	Eratosthenes(pole);

    unsigned long lastPrimes[X];
	unsigned long lastPrimesCount = 0;

	for (unsigned long i = bitset_size(pole); i > 0; i--) {
		if (bitset_getbit(pole, i) == 0) lastPrimes[lastPrimesCount++] = i;	
		if (lastPrimesCount == X) {
            while (lastPrimesCount > 0) printf("%lu\n", lastPrimes[--lastPrimesCount]);
            break;
        }
	}

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	
    return 0;
}
