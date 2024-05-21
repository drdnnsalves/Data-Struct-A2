#include <iostream>
#include "functionsSelection.h"
#include <cstdlib>

using namespace std;

namespace SelectionFunctions {

    template<typename T>
    Node<T>* createNode(int iValue) {
        Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
        temp->iPayload = iValue;
        temp->ptrNext = nullptr;
        temp->ptrPrev = nullptr;
        
        return temp;
    }

    template<typename T>
    void displayList(Node<T>* ptrNode) {
        if (ptrNode == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        
        if (ptrNode->ptrPrev != nullptr) {
            cout << "The element is in the middle or at the end of the list." << endl;
            return;
        }
        
        Node<T>* ptrTemp = ptrNode;
        cout << "Payload: ";
        
        while (ptrTemp != nullptr) {
            cout <<  ptrTemp->payload << " ";
            ptrTemp = ptrTemp->ptrNext;
        }
        
        cout << endl;
    }

    template<typename T>
    void insertEnd(Node<T>** ptrHead, T value) {
        Node<T>* ptrNewNode = createNode(value);

        if (*ptrHead == nullptr) {
            *ptrHead = ptrNewNode; 
            return;
        }
        
        Node<T>* ptrTemp = *ptrHead;
        while (ptrTemp->ptrNext != nullptr)
            ptrTemp = ptrTemp->ptrNext;
        
        ptrNewNode->ptrPrev = ptrTemp;
        ptrTemp->ptrNext = ptrNewNode;
    }

    template<typename T>
    void deleteList(Node<T>** ptrHead) {
        Node<T>* ptrCurrent = *ptrHead;
        Node<T>* ptrNext;

        while (ptrCurrent != nullptr) {
            ptrNext = ptrCurrent->ptrNext;
            free(ptrCurrent);
            ptrCurrent = ptrNext;
        }

        *ptrHead = nullptr;
    }

    template<typename T>
    void swapValue(Node<T>** ptrNode1, Node<T>** ptrNode2) {
        T tempPayload = (*ptrNode1)->payload;
        (*ptrNode1)->payload = (*ptrNode2)->payload;
        (*ptrNode2)->payload = tempPayload;
    }

    template<typename T>
    void listSelectionSort(Node<T>** ptrHead, int iLength) {
        for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++) {
            Node<T>* ptrCurrent = *ptrHead;

            for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++) {
                if (ptrCurrent->payload > ptrCurrent->ptrNext->payload) {
                    swapValue(&ptrCurrent, &(ptrCurrent->ptrNext));
                }
                ptrCurrent = ptrCurrent->ptrNext;
            }
        }
    }

    template<typename T>
    void optimizedListSelectionSort(Node<T>** ptrHead, int iLength) {
        Node<T>* ptrCurrent; 
        Node<T>* ptrMin;

        for (int i = 0; i < iLength - 1; i++) {
            ptrCurrent = *ptrHead;
            ptrMin = ptrCurrent;

            for (int j = i + 1; j < iLength; j++) {
                if (ptrCurrent->payload > ptrCurrent->ptrNext->payload) {
                    ptrMin = ptrCurrent->ptrNext;
                }
                ptrCurrent = ptrCurrent->ptrNext;
            }

            if (ptrMin != ptrCurrent) {
                swapValue(&ptrMin, &ptrCurrent);
            }
        }
    }

}