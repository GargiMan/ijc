# Makefile IJC DU2
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

all: tail

tail.o: tail.c

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o $@

clean:
	rm -f *.o tail

zip: *.c *.h Makefile
	zip xgerge01.zip *.c Makefile