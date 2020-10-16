# Makefile IJC DU2
# Autor: Marek Gergel, FIT

C = gcc -std=c99 -pedantic -Wall -Wextra -g
HTAB = htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_equal.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_iterator_valid.o htab_lookup_add.o htab_size.o

.PHONY: clean zip

all: tail libhtab.a libhtab.so

tail: tail.c
	$(C) $^ -o $@

%.o: %.c
	$(C) -fPIC -c $<  

libhtab.a: $(HTAB)
	ar crs $@ $^

libhtab.so: $(HTAB)
	$(C) -fPIC -shared  $^ -o $@

clean:
	rm -f *.o tail libhtab.a libhtab.so

zip: *.c *.h Makefile
	zip xgerge01.zip *.c *.h Makefile