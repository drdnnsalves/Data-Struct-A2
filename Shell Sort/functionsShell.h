#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace ShellFunctions {

    template<typename T>
    struct Node {
        T payload;
        Node* ptrNext;
        Node* ptrPrev;
    };

    template<typename T>
    Node<T>* createNode(T value);

    template<typename T>
    void displayList(Node<T>* ptrNode);

    template<typename T>
    void insertEnd(Node<T>** ptrHead, T value);

    template<typename T>
    void deleteList(Node<T>** ptrHead);

    template<typename T>
    void swapNodes(Node<T>* ptrNode1, Node<T>* ptrNode2);

    template<typename T>
    void shellSort(Node<T>* ptrHead, int iLength);

}

#include "functionsShell.cpp"

#endif
