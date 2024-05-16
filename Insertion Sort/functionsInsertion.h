#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

typedef struct Node {
    int iPayload; 
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Functions for LinkedLists
Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void deleteList(Node**);
void swapValue(Node**, Node**);
void listInsertionSort(Node**);

// Functions for Arrays
void swapValue(int&, int&);
void printArray(int[], int);
void inserctionSort(int[], int);

#endif