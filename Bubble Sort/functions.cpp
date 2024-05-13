#include <iostream>
#include "functions.h"
#include <cstdlib>

using namespace std;


// List Functions

Node* createNode(int iValue) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node) {
    if (node == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    
    if (node->ptrPrev != nullptr) {
        cout << "The element is in the middle or at the end of the list." << endl;
        return;
    }
    
    Node* temp = node;
    cout << "Payload: ";
    
    while (temp != nullptr) {
        cout <<  temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertEnd(Node** head, int iValue) {
    Node* newNode = createNode(iValue);

    if (*head == nullptr) {
        *head = newNode; 
        return;
    }
    
    Node* temp = *head;
    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != nullptr) {
        next = current->ptrNext;
        free(current);
        current = next;
    }

    *head = nullptr;
}

void swapValue(Node** Value_1, Node** Value_2) {
    int temp = (*Value_1)->iPayload;
    (*Value_1)->iPayload = (*Value_2)->iPayload;
    (*Value_2)->iPayload = temp;
}

void listBubbleSort(Node** head, int iLength) {
    Node* current = *head;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
        current = *head;
        for (int iInnerLoop = 0; iInnerLoop < iLength - iOuterLoop - 1; iInnerLoop++) {
            if (current->iPayload > current->ptrNext->iPayload) {
                swapValue(&current, &(current->ptrNext));
            }
            current = current->ptrNext;
        }
    }
}

void optimizedListBubbleSort(Node** head, int iLength) {
    Node* current = *head;
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
        current = *head;
        bUnordered = false;
        
        for (int iInnerLoop = 0; iInnerLoop < iLength - iOuterLoop - 1; iInnerLoop++) {
            if (current->iPayload > current->ptrNext->iPayload) {
                swapValue(&current, &(current->ptrNext));
                bUnordered = true;
            }
            current = current->ptrNext;
        }

        if (!bUnordered) {
            break;
        }
    }
}

// Array Functions

void swapValue(int& irefValue_1, int& irefValue_2) {
    int iTemp = irefValue_1;
    irefValue_1 = irefValue_2;
    irefValue_2 = iTemp;
    
}

void printArray(int arriNumbers[], int iLenght) {
    for(int i = 0; i < iLenght; i++) cout<<arriNumbers[i] << " ";
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLenght) {
    
    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iLenght-1; iInnerLoop++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop+1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
}

void otimizationBubbleSort(int arriNumbers[], int iLenght) {
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) {
        bUnordered = false;
        
        for (int iInnerLoop = 0; iInnerLoop < iLenght-1-iOuterLoop; iInnerLoop++) {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop+1]) {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
                bUnordered = true;
            }    
            
            if(bUnordered == false)
                break;
        }

    }
}
