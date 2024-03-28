#include "Multime.h"
#include <assert.h>
#include "IteratorMultime.h"
#include <exception>
#include <iostream>
#include "TestExtins.h"

using namespace std;

typedef int TElem;

bool rGreater(TComp e1, TComp e2) {
    if (e1 > e2) {
        return true;
    }
    else {
        return false;
    }
}

bool rLessEqual(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}


void testCreate(Relation r) {
    Multime s(r);
    assert(s.size() == 0);
    assert(s.isEmpty() == true);

    for (int i = -10; i < 10; i++) {
        assert(s.search(i) == false);
    }
    for (int i = -10; i < 10; i++) {
        assert(s.remove(i) == false);
    }

    IteratorMultime it = s.iterator();
    assert(it.valid() == false);
    try {
        it.urmator();
        assert(false);
    }
    catch (exception&) {
        assert (true);
    }
    try {
        it.element();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
}


void testAdd() {
    int vverif[10];
    int iverif;

    Multime s2(rGreater);
    for (int i = 0; i <= 3; i++) {
        s2.add(i);
    }
    for (int i = 5; i > 3; i--) {
        s2.add(i);
    }
    IteratorMultime it2 = s2.iterator();
    iverif = 0;
    while (it2.valid()) {
        vverif[iverif++] = it2.element();
        it2.urmator();
    }
    assert((vverif[0] == 5) && (vverif[1] == 4) && (vverif[2] == 3) && (vverif[3] == 2) && (vverif[4] == 1) && (vverif[5] == 0));
    assert(s2.isEmpty() == false);
    assert(s2.size() == 6);

    Multime s(rLessEqual);
    for (int i = 0; i <= 3; i++) {
        s.add(i);
    }
    for (int i = 5; i > 3; i--) {
        s.add(i);
    }
    IteratorMultime it = s.iterator();
    iverif = 0;
    while (it.valid()) {
        vverif[iverif++] = it.element();
        it.urmator();
    }
    assert((vverif[0] == 0) && (vverif[1] == 1) && (vverif[2] == 2) && (vverif[3] == 3) && (vverif[4] == 4) && (vverif[5] == 5));
    assert(s.isEmpty() == false);
    assert(s.size() == 6);

    for (int i = -10; i < 20; i++) {
        s.add(i);
    }
    assert(s.isEmpty() == false);
    assert(s.size() == 30);
    for (int i = 100; i > -100; i--) {
        s.add(i);
    }
    assert(s.isEmpty() == false);
    assert(s.size() == 200);
    for (int i = -200; i < 200; i++) {
        if (i <= -100) {
            assert(s.search(i) == false);
        }
        else if (i < 0) {
            assert(s.search(i) == true);
        }
        else if (i <= 100) {
            assert(s.search(i) == true);
        }
        else {
            assert(s.search(i) == false);
        }
    }
    for (int i = 10000; i > -10000; i--) {
        s.add(i);
    }
    assert(s.size() == 20000);
}


void testRemove(Relation r) {
    Multime s(r);
    for (int i = -100; i < 100; i++) {
        assert(s.remove(i) == false);
    }
    assert(s.size() == 0);

    for (int i = -100; i < 100; i = i + 2) {
        s.add(i);
    }
    for (int i = -100; i < 100; i++) {
        if (i % 2 == 0) {
            assert(s.remove(i) == true);
        }
        else {
            assert(s.remove(i) == false);
        }
    }
    assert(s.size() == 0);

    for (int i = -100; i <= 100; i = i + 2) {
        s.add(i);
    }

    for (int i = 100; i > -100; i--) {
        if (i % 2 == 0) {
            assert(s.remove(i) == true);
        }
        else {
            assert(s.remove(i) == false);
        }
    }
    assert(s.size() == 1);

    s.remove(-100);
    assert(s.size() == 0);

    for (int i = -100; i < 100; i++) {
        s.add(i);
        s.add(i);
        s.add(i);
        s.add(i);
        s.add(i);
    }

    assert(s.size() == 200);
    for (int i = -200; i < 200; i++) {
        if (i < -100 || i >= 100) {
            assert(s.remove(i) == false);
        }
        else {
            assert(s.remove(i) == true);
            assert(s.remove(i) == false);
        }
    }
    assert(s.size() == 0);

}


void testIterator(Relation r) {
    Multime s(r);
    IteratorMultime it = s.iterator();
    assert(it.valid() == false);

    for (int i = 0; i < 100; i++) {
        s.add(33);
    }
    assert(s.size() == 1);

    IteratorMultime it2 = s.iterator();
    assert(it2.valid() == true);
    TElem elem = it2.element();
    assert(elem == 33);
    it2.urmator();
    assert(it2.valid() == false);
    try {
        it2.urmator();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        it2.element();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    it2.prim();
    assert(it2.valid() == true);

    Multime s2(r);
    for (int i = -100; i < 100; i++) {
        s2.add(i);
        s2.add(i);
        s2.add(i);
    }

    IteratorMultime it3 = s2.iterator();
    assert(it3.valid() == true);
    for (int i = 0; i < 200; i++) {
        it3.urmator();
    }
    assert(it3.valid() == false);
    it3.prim();
    assert(it3.valid() == true);

    Multime s3(r);
    for (int i = 0; i < 200; i = i + 4) {
        s3.add(i);
    }

    IteratorMultime it4 = s3.iterator();
    assert(it4.valid() == true);
    int count = 0;
    while (it4.valid()) {
        TElem e = it4.element();
        assert(e % 4 == 0);
        it4.urmator();
        count++;
    }
    assert(count == 50);
}



void testQuantity(Relation r) {
    Multime s(r);
//    print_debug("Began quantity add!");
    for (int i = 10; i >= 1; i--) {
        for (int j = -30000; j < 30000; j = j + i) {
            s.add(j);
        }
    }
    assert(s.size() == 60000);
//    print_debug("Passed quantity add!");
    IteratorMultime it = s.iterator();
    assert(it.valid() == true);
    for (int i = 0; i < s.size(); i++) {
        it.urmator();
    }
    it.prim();
//    print_debug("Began quantity search!");
    while (it.valid()) {
        TElem e = it.element();
        assert(s.search(e) == true);
        it.urmator();
    }
    assert(it.valid() == false);
//    print_debug("Passed quantity search!");
//    print_debug("Began quantity remove!");
    for (int i = 0; i < 10; i++) {
        for (int j = 40000; j >= -40000; j--) {
            s.remove(j);
        }
    }
    assert(s.size() == 0);
//    print_debug("Passed quantity remove!");
}


void test_anterior(Relation r) {
    Multime m(r);
    IteratorMultime im = m.iterator();
    try {
        im.anterior();
        assert(false);
    } catch (exception &ex){

    }
    m.add(3);
    im.prim();
    im.anterior();
    assert(im.valid() == false);

    m.add(1);
    m.add(2);
    m.add(4);
    im.prim();

    assert(im.element() == 1);
    im.urmator();
    im.urmator();
    assert(im.element() == 3);
    im.anterior();
    assert(im.element() == 2);

}

void testAllExtended() {
    testCreate(rLessEqual);
    testAdd();
    testRemove(rLessEqual);
    testRemove(rGreater);
    testIterator(rLessEqual);
    testIterator(rGreater);
    testQuantity(rLessEqual);
    testQuantity(rGreater);
    test_anterior(rLessEqual);

}









//void print_debug(const std::string &s) {
//    if (DEBUG == 0)
//        return;
//    std::cout << s << '\n';
//    std::cout.flush();
//}