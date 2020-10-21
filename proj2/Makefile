# Makefile IJC DU2
# Autor: Marek Gergel, FIT

C = gcc -std=c99 -pedantic -Wall -Wextra -g
HTAB = htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_equal.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_iterator_valid.o htab_lookup_add.o htab_size.o

.PHONY: clean

all: tail libhtab.a libhtab.so wordcount wordcount-dynamic

tail.o: tail.c
	$(C) -c $<

tail: tail.o
	$(C) $^ -o $@

io.o: io.c io.h
	$(C) -c $<

wordcount.o: wordcount.c
	$(C) -c $<

wordcount: wordcount.o io.o libhtab.a
	$(C) $^ -o $@ -static

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(C) $^ -o $@

%.o: %.c htab.h htab_structs.h
	$(C) -fPIC -c $<  

libhtab.a: $(HTAB)
	ar crs $@ $^

libhtab.so: $(HTAB)
	$(C) -fPIC -shared  $^ -o $@

clean:
	rm -f *.o tail libhtab.a libhtab.so wordcount wordcount-dynamic wordcount-

zip:
	zip xgerge01.zip *.c *.h Makefile

wordcount-: wordcount-.cc
	g++ -std=c++11 -O2 $^ -o $@