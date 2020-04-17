# Makefile IJC DU1
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra

%.o : %.c
	$(CC) $(CFLAGS) -c $< -lm

all: primes primes-i steg-decode

ppm.o: ppm.c ppm.h

error.o: error.c error.h

primes.o: primes.c eratosthenes.h bitset.h

steg-decode.o: steg-decode.c eratosthenes.h bitset.h ppm.h

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h 

primes: eratosthenes.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o primes.o error.o -o $@ -lm

primes-i: eratosthenes.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o primes.o error.o -DUSE_INLINE -o $@ -lm

steg-decode: steg-decode.o ppm.o error.o eratosthenes.o 
	$(CC) $(CFLAGS) steg-decode.o ppm.o error.o eratosthenes.o -o $@ -lm

run: all
	./primes
	./primes-i

clean: 
	$(RM) *.o primes primes-i steg-decode xgerge01.zip

zip: *.c *.h Makefile
	zip xgerge01.zip *.c *.h Makefile
