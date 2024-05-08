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
void listSelectionSort(Node**, int);
void optimizedListSelectionSort(Node**, int);

// Functions for Arrays
void swapValue(int&, int&);
void printArray(int[], int);
void selectionSort(int[], int);
void optimizedSelectionSort(int[], int);

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    double dSumSelectionSort = 0;
    double dSumSquaredSelectionSort = 0;
    double dSumOptSelectionSort = 0;
    double dSumSquaredOptSelectionSort = 0;

    for (int i = 0; i < iNumLists; ++i) {
        Node* ptrHeadSelectionSort = nullptr;
        Node* ptrHeadOptSelectionSort = nullptr;

        // Create lists
        for (int j = 0; j < iSize; j++) {
            int value = rand() % 1000 + 1;
            insertEnd(&ptrHeadSelectionSort, value);
            insertEnd(&ptrHeadOptSelectionSort, value);
        }

        // Execution times for listSelectionSort
        auto startSelectionSort = chrono::high_resolution_clock::now();
        listSelectionSort(&ptrHeadSelectionSort, iSize);
        auto endSelectionSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSelectionSort = endSelectionSort - startSelectionSort;

        double timeSelectionSort = durationSelectionSort.count();
        dSumSelectionSort += timeSelectionSort;
        dSumSquaredSelectionSort += timeSelectionSort * timeSelectionSort;

        // Execution times for optimizedListSelectionSort
        auto startOptSelectionSort = chrono::high_resolution_clock::now();
        optimizedListSelectionSort(&ptrHeadOptSelectionSort, iSize);
        auto endOptSelectionSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationOptSelectionSort = endOptSelectionSort - startOptSelectionSort;

        double timeOptSelectionSort = durationOptSelectionSort.count();
        dSumOptSelectionSort += timeOptSelectionSort;
        dSumSquaredOptSelectionSort += timeOptSelectionSort * timeOptSelectionSort;

        deleteList(&ptrHeadSelectionSort);
        deleteList(&ptrHeadOptSelectionSort);
    }

    // Mean for listSelectionSort
    double dMeanSelectionSort = dSumSelectionSort / iNumLists;

    // Standard Deviation for listSelectionSort
    double dVarianceSelectionSort = (dSumSquaredSelectionSort / iNumLists) - (dMeanSelectionSort * dMeanSelectionSort);
    double dStdDevSelectionSort = sqrt(dVarianceSelectionSort);

    // Mean for optimizedListSelectionSort
    double dMeanOptSelectionSort = dSumOptSelectionSort / iNumLists;

    // Standard Deviation for optimizedListSelectionSort
    double dVarianceOptSelectionSort = (dSumSquaredOptSelectionSort / iNumLists) - (dMeanOptSelectionSort * dMeanOptSelectionSort);
    double dStdDevOptSelectionSort = sqrt(dVarianceOptSelectionSort);

    cout << "listSelectionSort mean:               " << dMeanSelectionSort << " seconds" << endl;
    cout << "listSelectionSort standard deviation: " << dStdDevSelectionSort << " seconds" << endl << endl;

    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl << endl;

    cout << "optimizedListSelectionSort mean:               " << dMeanOptSelectionSort << " seconds" << endl;
    cout << "optimizedListSelectionSort standard deviation: " << dStdDevOptSelectionSort << " seconds" << endl;

    return 0;
}

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