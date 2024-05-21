#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace BubbleFunctions {

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
    void swapNodes(Node<T>** ptrNode1, Node<T>** ptrNode2);

    template<typename T>
    void listBubbleSort(Node<T>** ptrHead, int iLength);

    template<typename T>
    void optimizedListBubbleSort(Node<T>** ptrHead, int iLength);

}

#include "functionsBubble.cpp"

#endif