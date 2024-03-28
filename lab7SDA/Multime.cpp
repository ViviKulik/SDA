#include "Multime.h"

BSTNode *Multime::getMinimum(BSTNode *startingRoot) {
    BSTNode *currentNode = root;
    BSTNode *minNode = root;

    while (currentNode != nullptr) {
        minNode = currentNode;
        currentNode = currentNode->getLeftSon();
    }
    return minNode;
}

BSTNode *Multime::getMaximum(BSTNode *startingRoot) {
    BSTNode *currentNode = root;
    BSTNode *maxNode = root;

    while (currentNode != nullptr) {
        maxNode = currentNode;
        currentNode = currentNode->getRightSon();
    }
    return maxNode;
}

//O(h)
BSTNode *Multime::removeRecursively(BSTNode *node, TComp e, bool &removed) {
    if (node == nullptr) {
        return node;
    }

    if (e == node->getValue()) {
        removed = true;
        if (node->getLeftSon() == nullptr) {
            BSTNode* rightSon = node->getRightSon();
            delete node;
            return rightSon;
        }
        else if (node->getRightSon() == nullptr) {
            BSTNode* leftSon = node->getLeftSon();
            delete node;
            return leftSon;
        }
        else {
            BSTNode *maxNode = getMaximum(node->getLeftSon());
            node->setValue(maxNode->getValue());
            node->setLeftSon(removeRecursively(node->getLeftSon(), maxNode->getValue(), removed));
        }
    }
    else if (rel(e, node->getValue())) {
        node->setLeftSon(removeRecursively(node->getLeftSon(), e, removed));
    }
    else {
        node->setRightSon(removeRecursively(node->getRightSon(), e, removed));
    }
    return node;
}

Multime::Multime(Relation r): root{nullptr}, numberOfElements{0}, rel{r} {
}

//O(h)
bool Multime::add(TComp e) {
    BSTNode *current = root;
    BSTNode *parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (e == current->getValue()) {
            return false;
        }
        else if (rel(e, current->getValue())) {
            current = current->getLeftSon();
        }
        else {
            current = current->getRightSon();
        }
    }

    BSTNode *newNode = new BSTNode{e};
    if (root == nullptr) {
        root = newNode;
    }
    else if (rel(e, parent->getValue())) {
        parent->setLeftSon(newNode);
    }
    else {
        parent->setRightSon(newNode);
    }
    ++numberOfElements;
    return true;
}

//O(h)
bool Multime::remove(TComp e) {
    bool removed = false;
    root = removeRecursively(root, e, removed);
    if (removed)
        --numberOfElements;
    return removed;
}

//O(h)
bool Multime::search(TComp elem) const {
    BSTNode *current = root;

    while (current != nullptr) {
        if (current->getValue() == elem) {
            return true;
        }
        else if (rel(elem, current->getValue())) {
            current = current->getLeftSon();
        }
        else {
            current = current->getRightSon();
        }
    }
    return false;
}

int Multime::size() const {
    return numberOfElements;
}

bool Multime::isEmpty() const {
    return numberOfElements == 0;
}

IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

Multime::~Multime() {
    postOrderDeletion(root);
}






























void Multime::postOrderDeletion(BSTNode *node) {
    if (node == nullptr)
        return;
    if (node->isLeaf()) {
        delete node;
        return;
    }

    if (node->getLeftSon() != nullptr)
        postOrderDeletion(node->getLeftSon());
    if (node->getRightSon() != nullptr)
        postOrderDeletion(node->getRightSon());
    delete node;
}