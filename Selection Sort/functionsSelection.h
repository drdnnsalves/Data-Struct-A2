#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace SelectionFunctions {

    template<typename T>
    struct Node {
        T payload;
        Node* ptrNext;
        Node* ptrPrev;
    };

    // Functions for LinkedLists

    template<typename T>
    Node<T>* createNode(T value);

    template<typename T>
    void displayList(Node<T>*);

    template<typename T>
    void insertEnd(Node<T>**, T value);

    template<typename T>
    void deleteList(Node<T>**);

    template<typename T>
    void swapValue(Node<T>**, Node<T>**);

    template<typename T>
    void listSelectionSort(Node<T>**, int);

    template<typename T>
    void optimizedListSelectionSort(Node<T>**, int);

}

#include "functionsSelection.cpp"

#endif