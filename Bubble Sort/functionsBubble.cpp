#include <iostream>
#include "functionsBubble.h"
#include <cstdlib>

using namespace std;


// List Functions

namespace BubbleFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = (Node<T>*)malloc(sizeof(Node<T>));
        ptrTemp->payload = value;
        ptrTemp->ptrNext = nullptr;
        ptrTemp->ptrPrev = nullptr;
        
        return ptrTemp;
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
        Node<T>* ptrNext = nullptr;

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
    void listBubbleSort(Node<T>** ptrHead, int iLength) {
        Node<T>* ptrCurrent = *ptrHead;
        
        for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
            ptrCurrent = *ptrHead;
            for (int iInnerLoop = 0; iInnerLoop < iLength - iOuterLoop - 1; iInnerLoop++) {
                if (ptrCurrent->payload > ptrCurrent->ptrNext->payload) {
                    swapValue(&ptrCurrent, &(ptrCurrent->ptrNext));
                }
                ptrCurrent = ptrCurrent->ptrNext;
            }
        }
    }

    template<typename T>
    void optimizedListBubbleSort(Node<T>** ptrHead, int iLength) {
        Node<T>* ptrCurrent = *ptrHead;
        bool bUnordered = false;
        
        for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
            ptrCurrent = *ptrHead;
            bUnordered = false;
            
            for (int iInnerLoop = 0; iInnerLoop < iLength - iOuterLoop - 1; iInnerLoop++) {
                if (ptrCurrent->payload > ptrCurrent->ptrNext->payload) {
                    swapValue(&ptrCurrent, &(ptrCurrent->ptrNext));
                    bUnordered = true;
                }
                ptrCurrent = ptrCurrent->ptrNext;
            }

            if (!bUnordered)
                break;
        }
    }

}