# Makefile IJC DU1
# Autor: Marek Gergel, FIT

C = gcc -std=c11 -pedantic -Wall -Wextra -g

.PHONY: clean run

all: primes primes-i steg-decode steg-encode

%.o : %.c
	$(C) -c $< -lm

primes: eratosthenes.o primes.o error.o
	$(C) $^ -o $@ -lm

primes-i: eratosthenes.o primes.o error.o
	$(C) $^ -o $@ -lm -DUSE_INLINE

steg-decode: eratosthenes.o steg-decode.o ppm.o error.o
	$(C) $^ -o $@ -lm

steg-encode: eratosthenes.o steg-encode.o ppm.o error.o
	$(C) $^ -o $@ -lm

run: all
	./primes
	./primes-i

clean: 
	rm -f *.o primes primes-i steg-decode steg-encode

zip:
	zip xgerge01.zip *.c *.h Makefile
