#include "IteratorMultime.h"
#include "Multime.h"
#include <iostream>
#include <exception>

using std::exception;

const int STERS = INT_MAX - 1;

void IteratorMultime::deplasare_fata() {
    while (curent < multime.m && (multime.multime[curent] == INT_MAX || multime.multime[curent] == STERS))
        curent++;
}

IteratorMultime::IteratorMultime(const Multime &m) : multime(m) {
    /* de adaugat */
    curent = 0;
    deplasare_fata();
}


void IteratorMultime::prim() {
    /* de adaugat */
    curent = 0;
    deplasare_fata();
}


void IteratorMultime::urmator() {
    /* de adaugat */
    if (!valid())
        throw exception();
    curent++;
    deplasare_fata();
}


TElem IteratorMultime::element() const {
    if (!valid())
        throw exception();

    return multime.multime[curent];
}

bool IteratorMultime::valid() const {
    return (curent < multime.m && curent >= 0);
}

void IteratorMultime::deplasare_spate() {
    while (curent >= 0 && (multime.multime[curent] == INT_MAX || multime.multime[curent] == STERS))
        curent--;
}
void IteratorMultime::anterior() {
    if (!valid())
        throw exception();
    curent--;
    deplasare_spate();
}
