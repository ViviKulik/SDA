//
// Created by Vivian Kulik on 06.06.2023.
//

#ifndef LAB7SDA_ITERATORMULTIME_H
#define LAB7SDA_ITERATORMULTIME_H

#include "Multime.h"
#include <stack>
#include "BSTNode.h"

class Multime;
typedef int TComp;

class IteratorMultime {
    friend class Multime;

private:
    const Multime& set;
    BSTNode* currentNode;
    std::stack <BSTNode*> stack;
    IteratorMultime(const Multime& set);

public:
    //sets the iterator to the prim element of the container
    void prim();

    //moves the iterator to the urmator element
    //throws exception if the iterator is not valid
    void urmator();

    //move the iterator to the previous element
    //throws exception if the iterator is not valid
    void anterior();

    //checks if the iterator is valid
    bool valid() const;

    //returns the value of the current element from the iterator
    // throws exception if the iterator is not valid
    TComp element() const;
};

#endif //LAB7SDA_ITERATORMULTIME_H
