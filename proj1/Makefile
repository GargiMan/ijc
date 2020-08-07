# Makefile IJC DU1
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra

.PHONY: run clean zip

%.o : %.c
	$(CC) $(CFLAGS) -c $< -lm

all: primes primes-i steg-decode

ppm.o: ppm.c ppm.h

error.o: error.c error.h

primes.o: primes.c

steg-decode.o: steg-decode.c

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h 

primes: eratosthenes.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o primes.o error.o -o $@ -lm

primes-i: eratosthenes.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o primes.o error.o -DUSE_INLINE -o $@ -lm

steg-decode: eratosthenes.o steg-decode.o ppm.o error.o
	$(CC) $(CFLAGS) eratosthenes.o steg-decode.o ppm.o error.o  -o $@ -lm

run: all
	./primes
	./primes-i

clean: 
	$(RM) *.o primes primes-i steg-decode

zip: *.c *.h Makefile
	zip xgerge01.zip *.c *.h Makefile