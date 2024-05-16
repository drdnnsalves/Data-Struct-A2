#include <iostream>
#include "functions.h"
#include <cstdlib>

using namespace std;


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

void listSelectionSort(Node** head, int iLength) {
    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++) {
        Node* current = *head;

        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++) {
            if (current->iPayload > current->ptrNext->iPayload) {
                swapValue(&current, &(current->ptrNext));
            }
            current = current->ptrNext;
        }
    }
}

void optimizedListSelectionSort(Node** head, int iLength) {
    Node *current; 
    Node *min;

    for (int i = 0; i < iLength - 1; i++) {
        current = *head;
        min = current;

        for (int j = i + 1; j < iLength; j++) {
            if (current->iPayload > current->ptrNext->iPayload) {
                min = current->ptrNext;
            }
            current = current->ptrNext;
        }

        if (min != current) {
            swapValue(&min, &current);
        }
    }
}

void swapValue(int& irefValue_1, int& irefValue_2) {
    int iTemp = irefValue_1;
    irefValue_1 = irefValue_2;
    irefValue_2 = iTemp;
    
}

void printArray(int arriNumbers[], int iLenght) {
    for(int i = 0; i < iLenght; i++) cout<<arriNumbers[i] << " ";
    cout << endl;
}

void selectionSort(int arriNumbers[], int iLenght) {
    
    for (int iOuterLoop = 0; iOuterLoop < iLenght; iOuterLoop++)
        for (int iInnerLoop = iOuterLoop+1; iInnerLoop < iLenght; iInnerLoop++)
            if(arriNumbers[iOuterLoop] > arriNumbers[iInnerLoop])
                swapValue(arriNumbers[iOuterLoop], arriNumbers[iInnerLoop]);
}

void optimizedSelectionSort(int arriNumbers[], int iLenght) {
    int iminValue = 0;
    int iSwapIndex = 0;
    
    for (int iOuterLoop = 0; iOuterLoop < iLenght; iOuterLoop++) {
        iminValue = arriNumbers[iOuterLoop];
        iSwapIndex = iOuterLoop;
        
        for (int iInnerLoop = iOuterLoop+1; iInnerLoop < iLenght; iInnerLoop++) {
            if(iminValue > arriNumbers[iInnerLoop]) {
                iminValue = arriNumbers[iInnerLoop];
                iSwapIndex = iInnerLoop;
            }
        }
        
        swapValue(arriNumbers[iOuterLoop], arriNumbers[iSwapIndex]);
    }
}