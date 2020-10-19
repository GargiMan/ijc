#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "io.h"

/*
    Cislo jsem vybral na zaklade zdroje uvedeneho nize.
    Cislo by melo byt 1.3 nasobek vsech potencionalnich hodnot (pro nas slova) a melo by byt prvocislo.
    Budu hledat 15000 slov -> 19500 a nejblizsi prvocilo je 19501
    Zdroj: http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-8.html
*/
#define HTAB_SIZE 19501
#define WORD_LEN_LIM 127

int main(void) {
    FILE *f = stdin;

    char* word = malloc(WORD_LEN_LIM * sizeof(char));
    if (!word) {
        fprintf(stderr, "Chyba alokace paměti.\n");
        return EXIT_FAILURE;
    }

    htab_t *table = htab_init(HTAB_SIZE);
    if (!table) {
        fprintf(stderr, "Chyba alokace paměti.\n");
        return EXIT_FAILURE;
    }

    int wordLength = 0;
    bool warningMsgShown = false;

    while((wordLength = get_word(word, WORD_LEN_LIM, f)) != EOF){
        // kdyz slovo bylo delsi nez limit -> jedno varovani
        if(wordLength >= WORD_LEN_LIM && !warningMsgShown){
            fprintf(stderr, "Slovo bylo prilis dluhe. Doslo k omezenemu nacteni.\n");
            warningMsgShown = true;
        }
        //pridani slova do tabulky
        htab_iterator_t iterator = htab_lookup_add(table, word);

        //overeni spravneho pridani slova
        if(!htab_iterator_valid(iterator)){
            fprintf(stderr, "Nebylo mozne vlozit slovo do tabulky.\n");
            htab_free(table);
            free(word);
            return EXIT_FAILURE;
        }

        //inkrementuji pocet slov
        htab_iterator_set_value(iterator, (htab_iterator_get_value(iterator) + 1));
    }

    //vypis hodnot tabulky
    htab_iterator_t counter = htab_begin(table);
    htab_iterator_t end = htab_end(table);
    while (!htab_iterator_equal(counter, end)) {
        printf("%s\t%d\n", htab_iterator_get_key(counter), htab_iterator_get_value(counter));
        counter = htab_iterator_next(counter);
    }

    free(word);
    htab_free(table);
    return EXIT_SUCCESS;
}
