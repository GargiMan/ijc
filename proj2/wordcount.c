

#include "htab.h"


int main() {



//fprintf(stdout,"%s\t%i\n",name,num);


    return 0;
}  
   
/*
   Výstupy programů musí být pro stejný vstup stejné (kromě pořadí a příliš
   dlouhých slov).

   Výsledný program se musí jmenovat "wordcount.c".

   Implementujte tabulku s rozptýlenými položkami (hash table) - viz dále.
   Veškeré operace s tabulkou budou v samostatné knihovně (vytvořte statickou
   i dynamickou/sdílenou verzi).  V knihovně musí být prakticky každá funkce ve
   zvláštním modulu -- to například umožní případnou výměnu htab_hash_fun() ve vašem
   staticky sestaveném programu. (V dynamicky sestaveném programu je to možné vždy.)
   Vyzkoušejte si to: definujte svoji verzi htab_hash_fun() v programu
   s podmíněným překladem -- použijte #ifdef HASHTEST.

   Knihovna s tabulkou se musí jmenovat
   "libhtab.a" (na Windows je možné i "htab.lib") pro statickou variantu,
   "libhtab.so" (na Windows je možné i "htab.dll") pro sdílenou variantu
   a rozhraní "htab.h".

   Podmínky:
    - Implementace musí být dynamická (malloc/free) a musíte zvládnout
      správu paměti v C (použijte valgrind, nebo jiný podobný nástroj).

    - Vhodná rozptylovací funkce pro řetězce je podle literatury
      (http://www.cse.yorku.ca/~oz/hash.html - varianta sdbm):

        size_t htab_hash_fun(const char *str) {
          uint32_t h=0;     // musí mít 32 bitů
          const unsigned char *p;
          for(p=(const unsigned char*)str; *p!='\0'; p++)
              h = 65599*h + *p;
          return h;
        }

      její výsledek modulo arr_size určuje index do tabulky:
        index = (htab_hash_fun("mystring") % arr_size);
      Zkuste použít i jiné podobné funkce a porovnejte efektivitu.

    - Tabulka je (pro knihovnu privátní) struktura obsahující pole seznamů,
      jeho velikost a počet položek tabulky v následujícím pořadí:

         +----------+
         | size     | // aktuální počet záznamů [key,data,next]
         +----------+
         | arr_size | // velikost následujícího pole ukazatelů
         +----------+
         +---+
         |ptr|-->[key,data,next]-->[key,data,next]-->[key,data,next]--|
         +---+
         |ptr|--|
         +---+
         |ptr|-->[key,data,next]-->[key,data,next]--|
         +---+
         |ptr|--|
         +---+

      Položka .arr_size je velikost následujícího pole ukazatelů (použijte
      C99: "flexible array member"). Paměť pro strukturu se dynamicky alokuje
      tak velká, aby se do ní vešly i všechny položky pole.
      V programu zvolte vhodnou velikost pole a v komentáři zdůvodněte vaše
      rozhodnutí.
      (V obrázku platí velikost .arr_size==4 a počet položek .size==5.)
      Rozhraní knihovny obsahuje jen _neúplnou_deklaraci_ struktury, definice
      je uživateli knihovny skryta (jde o formu zapouzdření - "encapsulation").
*/