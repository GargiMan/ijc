# Makefile IJC DU2
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra

all: tail

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o $@

run: all
	./tail file
	./tail file -n 3
	./tail file -n +15

ref:
	tail file
	tail file -n 3
	tail file -n +15

clean:
	$(RM) tail xgerge01.zip

zip: *.c Makefile # *.h - doplnit ak bude treba 
	zip xgerge01.zip *.c *.c Makefile