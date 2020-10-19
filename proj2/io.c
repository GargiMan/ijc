#include "io.h"

int get_word(char *s, int max, FILE *f) {
    //zkontrolovat file
    if (!f) {
        fprintf(stderr, "Soubor nesmi byt null.\n");
        return EOF;
    }

    int character = 0;

    while ((character = fgetc(f)) && isspace(character)) {
        //skip first space
        ;
    }

    if (character == EOF) {
        return character;
    }

    int counter = 0;
    s[counter++] = character;

    //naplnit pole až do EOF nebo do isspace
    while (counter < (max - 1)) {
        character = fgetc(f);
        if (character == EOF || isspace(character)) break;
        s[counter++] = character;
    }

    //terminate string
    s[counter] = '\0';

    if ((max - 1) == counter) {
        //kdyz slovo bylo delsi nez limit, preskocit zbytek slova
        while ((character = fgetc(f)) != EOF && !isspace(character)) {
            counter++;
        } 
    }
    return counter;
}