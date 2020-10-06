// htab.h -- rozhrani knihovny htab (reseni IJC-DU2)
// Licence: zadna (Public domain)

// nasledujici radky zabrani nasobnemu vlozeni:
#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>     // size_t
#include <stdbool.h>    // bool

// Tabulka:
struct htab;                            // neuplna deklarace struktury - uzivatel nevidi obsah
typedef struct htab htab_t;             // typedef podle zadani
 
// Zaznam do tabulky:
struct htab_item;                       // neuplna deklarace struktury

// Typy:
typedef const char * htab_key_t;        // typ klice v zazname
typedef int htab_value_t;               // typ hodnoty v zazname

// Iterator:
typedef struct htab_iterator {
    struct htab_item *ptr;              // ukazatel na polozku
    const htab_t *t;                    // ve ktere tabulce
    size_t idx;                         // ve kterem seznamu tabulky (TODO: optimalizovat?)
} htab_iterator_t;                      // typedef podle zadani

// rozptylovaci (hash) funkce (stejna pro vsechny tabulky v programu)
// pokud si v programu definujete stejnou funkci, pouzije se ta vase
size_t htab_hash_fun(htab_key_t str);

// funkce pro praci s tabulkou:
htab_t *htab_init(size_t n);                                                  // konstruktor tabulky
size_t htab_size(const htab_t * t);                                           // pocet zaznamu v tabulce
size_t htab_bucket_count(const htab_t * t);                                   // velikost pole ptr (tabulky)

htab_iterator_t htab_find(htab_t * t, htab_key_t key);                        // hledani klice v tabulce
htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key);                  // hledani klice v tabulce (ak nenajde, tak vytvori)

void htab_erase(htab_t * t, htab_iterator_t it);                              // rusi zadany zaznam

// funkce pro praci s iteratorem:
htab_iterator_t htab_begin(const htab_t * t);                                 // iterator na prvni zaznam
htab_iterator_t htab_end(const htab_t * t);                                   // iterator _za_ posledni zaznam
htab_iterator_t htab_iterator_next(htab_iterator_t it);                       // iterator++

// test: iterator != end()
inline bool htab_iterator_valid(htab_iterator_t it) { return it.ptr!=NULL; }
// test: iterator1 == iterator2
inline bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2) { return it1.ptr==it2.ptr && it1.t == it2.t; }

// cteni a zapis pres iterator
htab_key_t htab_iterator_get_key(htab_iterator_t it);                         // vraci klic ze zaznamu iteratora
htab_value_t htab_iterator_get_value(htab_iterator_t it);                     // vraci hodnotu ze zaznamu iteratora
htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val);   // zmeni a vraci hodnotu ze zaznamu iteratora

void htab_clear(htab_t * t);                                                  // rusi vsechny zaznamy
void htab_free(htab_t * t);                                                   // destruktor tabulky

#endif // __HTAB_H__