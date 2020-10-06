# Makefile IJC DU2
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

.PHONY: clean zip run

all: tail

tail.o: tail.c

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o $@

run:
	./tail

clean:
	rm -f *.o tail

zip: *.c *.h Makefile
	zip xgerge01.zip *.c *.h Makefile