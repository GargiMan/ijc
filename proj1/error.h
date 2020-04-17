// error.h
// Řešení IJC-DU1, příklad B), 17.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
//

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);