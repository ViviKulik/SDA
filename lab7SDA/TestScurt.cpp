#include "TestScurt.h"
#include "Multime.h"
#include "IteratorMultime.h"
#include <assert.h>
#include <iostream>

bool r2(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}


void testAll() {
    int vverif[5];
    int iverif;
    TComp e;

    Multime s1(r2);
    assert(s1.add(5) == true);
    assert(s1.add(1) == true);
    assert(s1.add(10) == true);
//    printDebug("Passed short add!");
    IteratorMultime it1 = s1.iterator();
    it1.prim();
    e = it1.element();
    iverif = 0;
    vverif[iverif++] = e;
    it1.urmator();
    while (it1.valid()) {
        assert(e < it1.element());
        e = it1.element();
        vverif[iverif++] = e;
        it1.urmator();
    }
    assert((vverif[0] == 1) && (vverif[1] == 5) && (vverif[2] == 10));
//    printDebug("Passed short iterator!");


    Multime s(r2);
    //return;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5) == true);
    assert(s.add(1) == true);
    assert(s.add(10) == true);
    assert(s.add(7) == true);
    assert(s.add(1) == false);
    assert(s.add(10) == false);
    assert(s.add(-3) == true);
    assert(s.size() == 5);
//    printDebug("Passed short add + size!");
    assert(s.search(10) == true);
    assert(s.search(16) == false);
//    printDebug("Passed short search!");
    assert(s.remove(1) == true);
    assert(s.remove(6) == false);
//    printDebug("Passed short remove!");
    assert(s.size() == 4);
//    printDebug("Passed short remove + size!");


    IteratorMultime it = s.iterator();
    iverif = 0;
    it.prim();
    e = it.element();
    vverif[iverif++] = e;
    it.urmator();
    while (it.valid()) {
        assert(r2(e, it.element()));
        e = it.element();
        vverif[iverif++] = e;
        it.urmator();
    }
    assert((vverif[0] == -3) && (vverif[1] == 5) && (vverif[2] == 7) && (vverif[3] == 10));
//    printDebug("Passed short iterator 2!");
//    printDebug("PASSED SHORT TESTS!");
}

void printDebug(const std::string& s) {
    if (debug == 0)
        return;
    std::cout << s << '\n';
    std::cout.flush();
}