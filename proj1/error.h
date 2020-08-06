// error.h
// Řešení IJC-DU1, příklad B), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// hlavicka suboru error.c

#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif //ERROR_H