# Makefile IJC DU2
# Autor: Marek Gergel, FIT

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g
HTAB = htab.h htab_structs.h htab_begin.c htab_bucket_count.c htab_clear.c htab_end.c htab_erase.c htab_find.c htab_free.c htab_hash_fun.c htab_init.c htab_iterator_equal.c htab_iterator_get_key.c htab_iterator_get_value.c htab_iterator_next.c htab_iterator_set_value.c htab_iterator_valid.c htab_lookup_add.c htab_size.c

.PHONY: clean zip run

all: tail libhtab.a libhtab.so

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o $@

libhtab.a: $(HTAB)
	$(CC) $(CFLAGS) -shared -fPIC $(HTAB) -o $@

libhtab.so: $(HTAB)
	$(CC) $(CFLAGS) -shared -fPIC $(HTAB) -o $@

run:
	./tail

clean:
	rm -f *.o tail libhtab.a libhtab.so

zip: *.c *.h Makefile
	zip xgerge01.zip *.c *.h Makefile