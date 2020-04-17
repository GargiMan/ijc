// error.c
// Řešení IJC-DU1, příklad B), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
//

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end (args);
}

void error_exit(const char *fmt, ...) {
    va_list args;
    va_start (args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end (args);
    exit(1);
}