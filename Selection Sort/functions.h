#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

struct Node {
    int iPayload; 
    Node* ptrNext;
    Node* ptrPrev;
};

// Functions for LinkedLists
Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void deleteList(Node**);
void swapValue(Node**, Node**);
void listSelectionSort(Node**, int);
void optimizedListSelectionSort(Node**, int);

// Functions for Arrays
void swapValue(int&, int&);
void printArray(int[], int);
void selectionSort(int[], int);
void optimizedSelectionSort(int[], int);

#endif