#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace TreeFunctions {

    template<typename T>
    struct Node {
        T payload;
        Node* ptrLeft;
        Node* ptrRight;
        Node* ptrNext;
    };

    template<typename T>
    Node<T>* createNode(T value);

    template<typename T>
    Node<T>* insertNode(Node<T>* startNode, T value);

    template<typename T>
    int treeHeight(Node<T>* ptrStartingNode);

    template<typename T>
    void bfsTraversal(Node<T>* ptrStartingNode, T value);

    template<typename T>
    bool traversePreOrder(Node<T>* ptrStartingNode, T value);

    template<typename T>
    bool traverseInOrder(Node<T>* ptrStartingNode, T value);

    template<typename T>
    bool traversePostOrder(Node<T>* ptrStartingNode, T value);


}

#include "functionsTree.cpp"

#endif
