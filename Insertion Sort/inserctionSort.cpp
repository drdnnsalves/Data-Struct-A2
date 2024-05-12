#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>

using namespace std;

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

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    double dSumInserction = 0;
    double dSumSquaredInserction = 0;

    for (int i = 0; i < iNumLists; ++i) {
        Node* ptrHeadInserction = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int value = rand() % iSize + 1;
            insertEnd(&ptrHeadInserction, value);
        }

        // Execution times for listInserctionSort
        auto startInserction = chrono::high_resolution_clock::now();
        listInsertionSort(&ptrHeadInserction);
        auto endInserction = chrono::high_resolution_clock::now();
        chrono::duration<double> durationInserction = endInserction - startInserction;

        double timeInserction = durationInserction.count();
        dSumInserction += timeInserction;
        dSumSquaredInserction += timeInserction * timeInserction;

        deleteList(&ptrHeadInserction);
    }

    // Mean for listInserctionSort
    double dMeanInserction = dSumInserction / iNumLists;

    // Standard Deviation for listInserctionSort
    double dVarianceInserction = (dSumSquaredInserction / iNumLists) - (dMeanInserction * dMeanInserction);
    double dStdDevInserction = sqrt(dVarianceInserction);

    cout << "listInserctionSort mean:               " << dMeanInserction << " seconds" << endl;
    cout << "listInserctionSort standard deviation: " << dStdDevInserction << " seconds" << endl << endl;

    return 0;
}

// List Functions

Node* createNode(int iValue) {
    Node* temp = (Node*) malloc(sizeof(Node));
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

void listInsertionSort(Node** head) {
    if (*head == nullptr || (*head)->ptrNext == nullptr)
        return;

    Node* sorted = nullptr;
    Node* current = *head;  

    while (current != nullptr) {
        Node* next = current->ptrNext; 
        if (sorted == nullptr || sorted->iPayload >= current->iPayload) {
            current->ptrNext = sorted;
            current->ptrPrev = nullptr;
            if (sorted != nullptr)
                sorted->ptrPrev = current;

            sorted = current;
        } 
        else {
            Node* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload)
                temp = temp->ptrNext;

            current->ptrNext = temp->ptrNext;
            current->ptrPrev = temp;
            if (temp->ptrNext != nullptr)
                temp->ptrNext->ptrPrev = current;

            temp->ptrNext = current;
        }
        current = next;
    }

    *head = sorted;
}


// Array Functions

void swapValue(int& irefValue_1, int& irefValue_2) {
    int iTemp = irefValue_1;
    irefValue_1 = irefValue_2;
    irefValue_2 = iTemp;
    
}

void printArray(int arriNumbers[], int iLenght) {
    for(int i = 0; i < iLenght; i++) 
        cout<<arriNumbers[i] << " ";

    cout << endl;
}

void inserctionSort(int arriNumbers[], int iLenght) {
    int iInsertValue = 0; 
    int iInnerLoop = 0;
    
    for (int iOuterLoop = 1; iOuterLoop < iLenght; iOuterLoop++) {
        iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;
        
        while (iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0) {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }

        arriNumbers[iInnerLoop + 1] = iInsertValue;
    }
}