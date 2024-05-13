#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

struct Node {
    int iPayload; 
    Node* ptrNext;
    Node* ptrPrev;
};

Node* createNode(int iValue);
void displayList(Node* node);
void insertEnd(Node** head, int iValue);
void deleteList(Node** head);
void swapNodes(Node** node1, Node** node2);
void listBubbleSort(Node** head, int iLength);
void optimizedListBubbleSort(Node** head, int iLength);

void swapValues(int& value1, int& value2);
void printArray(int arrNumbers[], int iLength);
void bubbleSort(int arrNumbers[], int iLength);
void optimizedBubbleSort(int arrNumbers[], int iLength);

#endif
