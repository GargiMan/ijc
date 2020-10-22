# Makefile IJC DU1
# Autor: Marek Gergel, FIT

C = gcc -std=c11 -pedantic -Wall -Wextra -g -lm

.PHONY: clean run

all: primes primes-i steg-decode steg-encode

%.o : %.c
	$(C) -c $<

primes: eratosthenes.o primes.o error.o
	$(C) $^ -o $@

primes-i: eratosthenes.o primes.o error.o
	$(C) $^ -o $@ -DUSE_INLINE

steg-decode: eratosthenes.o steg-decode.o ppm.o error.o
	$(C) $^ -o $@

steg-encode: eratosthenes.o steg-encode.o ppm.o error.o
	$(C) $^ -o $@

run: all
	./primes
	./primes-i

clean: 
	rm -f *.o primes primes-i steg-decode steg-encode

zip:
	zip xgerge01.zip *.c *.h Makefile
