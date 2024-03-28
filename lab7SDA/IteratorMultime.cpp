//
// Created by Vivian Kulik on 06.06.2023.
//
#include <stdexcept>
#include "IteratorMultime.h"
#include "Multime.h"
#include "TestExtins.h"
IteratorMultime::IteratorMultime(const Multime &set): set{set}, currentNode{nullptr}, stack{std::stack<BSTNode*>{}} {
    prim();
}

//teta(h)
void IteratorMultime::prim() {
    currentNode = set.root;
    stack = std::stack<BSTNode*>{};
    while (currentNode != nullptr) {
        stack.push(currentNode);
        currentNode = currentNode->getLeftSon();
    }

    if (stack.empty() == false) {
        currentNode = stack.top();
    }
    else {
        currentNode = nullptr;
    }
}


//O(h)
void IteratorMultime::urmator() {
    if (!valid())
        throw std::runtime_error("");

    BSTNode* node = stack.top();
    stack.pop();

    if (node->getRightSon() != nullptr) {
        node = node->getRightSon();
        while (node != nullptr) {
            stack.push(node);
            node = node->getLeftSon();
        }
    }

    if (stack.empty() == false) {
        currentNode = stack.top();
    }
    else {
        currentNode = nullptr;
    }
}


//O(h)
void IteratorMultime::anterior() {
    if(!valid())
        throw std::runtime_error("");

    BSTNode* node = stack.top();
    stack.pop();

    if (node->getLeftSon() != nullptr) {
        node = node->getLeftSon();
        while (node != nullptr) {
            stack.push(node);
            node = node->getRightSon();
        }
    }

    if (stack.empty() == false) {
        currentNode = stack.top();
    }
    else {
        currentNode = nullptr;
    }

}

bool IteratorMultime::valid() const {
    return currentNode != nullptr;
}

TComp IteratorMultime::element() const {
    if (!valid())
        throw std::runtime_error("");
    return currentNode->getValue();
}