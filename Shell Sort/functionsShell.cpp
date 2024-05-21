#include "functionsShell.h"
#include <cstdlib>

using namespace std;

namespace ShellFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = new Node<T>;
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

        Node<T>* ptrTemp = ptrNode;
        cout << "Payload: ";
        while (ptrTemp != nullptr) {
            cout << ptrTemp->payload << " ";
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
    void swapNodes(Node<T>* ptrNode1, Node<T>* ptrNode2) {
        T tempPayload = ptrNode1->payload;
        ptrNode1->payload = ptrNode2->payload;
        ptrNode2->payload = tempPayload;
    }

    template<typename T>
    void shellSort(Node<T>* ptrHead, int iLength) {
        if (ptrHead == nullptr || iLength < 2)
            return;

        // Calcula o valor inicial do Gap
        int iGap = 1;
        while (iGap < iLength) {
            iGap = iGap * 2 + 1;
        }

        while (iGap > 1) {
            // Reduz o valor de iGap.
            iGap = (iGap - 1) / 3;
            
            // Display em mor de fazer explicações do código na main
            cout << "Swapping elements of the list with Gap = "<< iGap << ": " << endl << endl;
            for (int i = iGap; i < iLength; ++i) {
                Node<T>* ptrTemp = ptrHead;
                for (int j = 0; j < i; ++j)
                    ptrTemp = ptrTemp->ptrNext;

                Node<T>* ptrCurrent = ptrTemp;
                Node<T>* ptrGapNode = ptrTemp;
                // Move ptrGapNode iGap posições para trás
                for (int j = 0; j < iGap; ++j) {
                    ptrGapNode = ptrGapNode->ptrPrev;
                }
                
                while (ptrGapNode != nullptr && ptrCurrent->payload < ptrGapNode->payload) {
                    swapNodes(ptrCurrent, ptrGapNode);

                    // Display em mor de fazer explicações do código na main
                    displayList(ptrHead);
                    cout << endl;

                    // Atualiza ptrCurrent
                    ptrCurrent = ptrGapNode;
                    // Move ptrGapNode iGap posições para trás
                    for (int j = 0; j < iGap; ++j) {
                        if (ptrGapNode->ptrPrev != nullptr)
                            ptrGapNode = ptrGapNode->ptrPrev;
                        else
                            break;
                    }
                }
            }
        }
    }
        
}


