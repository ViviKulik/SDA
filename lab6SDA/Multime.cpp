#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>


const int STERS = INT_MAX - 1;

Multime::Multime() {
    /* de adaugat */
    m = 100003;
    m1 = m - 1;
    for (int i = 0; i < m; i++)
        multime[i] = INT_MAX;///marcam pozitiile ca libere

}

int Multime::hashcode(int c) const {
    return c + 50000;
}

int Multime::d(int c, int i) const {
    int h = hashcode(c);
    return (h % m + i * (1 + h % m1)) % m;
}

//O(m)
bool Multime::adauga(TElem elem) {
    if (cauta(elem))//verificam daca elementul este deja in multime
        return false;
    //altfel il adaugam
    int poz;
    bool gasit = false;

    for (int i = 0; i < m && !gasit; i++) {
        poz = d(elem, i);
        if (multime[poz] == INT_MAX || multime[poz] == STERS)
            gasit = true;
    }
    if (gasit == true) {
        multime[poz] = elem;
        return true;
    }

    return false;
}

//O(m)
bool Multime::sterge(TElem elem) {
    /* de adaugat */
    int poz;
    for (int i = 0; i < m; i++) {
        poz = d(elem, i);

        if (multime[poz] == elem) {
            multime[poz] = STERS;
            return true;
        }
        if (multime[poz] == INT_MAX)
            return false;
    }

    return false;
}


bool Multime::cauta(TElem elem) const {
    /* de adaugat */
    int poz;
    for (int i = 0; i < m; i++) {
        poz = d(elem, i);
        if (multime[poz] == elem)
            return true;
        if (multime[poz] == INT_MAX)
            return false;
    }
    return false;
}


int Multime::dim() const {
    /* de adaugat */
    int nr = 0;
    for (int i = 0; i < m; i++)
        if (multime[i] != INT_MAX && multime[i] != STERS)
            nr++;

    return nr;
}

bool Multime::vida() const {
    /* de adaugat */
    if (dim() == 0)
        return true;
    return false;
}


//Multime::~Multime() {
//    /* de adaugat */
//}


IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

