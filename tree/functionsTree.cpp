#include "functionsTree.h"
#include <iostream>

using namespace std;

namespace TreeFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = (Node<T>*) malloc(sizeof(Node<T>));

        if(ptrTemp == nullptr) {
            cerr << "Error in createNode: memory allocation failed" << endl;
            exit(1);
        } 

        ptrTemp->payload = value;
        ptrTemp->ptrLeft = nullptr;
        ptrTemp->ptrRight = nullptr;
        ptrTemp->ptrNext = nullptr;

        return ptrTemp;
    }

    template<typename T>
    Node<T>* insertNode(Node<T>* startNode, T value) {
        if (startNode == nullptr) {
            return createNode(value);
        }
        if (value < startNode->payload) {
            startNode->ptrLeft = insertNode(startNode->ptrLeft, value); 
        }
        else {
            startNode->ptrRight = insertNode(startNode->ptrRight, value); 
        }

        return startNode; 
    }

    template<typename T>
    int treeHeight(Node<T>* ptrStartingNode) {
        if(ptrStartingNode == nullptr)
            return 0;
        else {
            int leftHeight = treeHeight(ptrStartingNode->ptrLeft);
            int rightHeight = treeHeight(ptrStartingNode->ptrRight);

            return 1 + max(leftHeight, rightHeight);
        }
    }

    template<typename T>
    void bfsTraversal(Node<T>* ptrStartingNode) {
        if (ptrStartingNode == nullptr)
            return;

        Node<T>* ptrFront = nullptr;
        Node<T>* ptrRear = nullptr;

        ptrRear = ptrFront = ptrStartingNode;

        while  (ptrFront != nullptr) {
            cout << ptrFront->payload << " ";

            if  (ptrFront->ptrLeft != nullptr) {
                ptrRear->ptrNext = ptrFront->ptrLeft;
                ptrRear = ptrRear->ptrNext;
            }
            if  (ptrFront->ptrRight != nullptr) {
                ptrRear->ptrNext = ptrFront->ptrRight;
                ptrRear = ptrRear->ptrNext;
            }

            ptrFront = ptrFront->ptrNext;
        }
    }

    template<typename T>
    void traversePreOrder(Node<T>* ptrStartingNode) {
        if(ptrStartingNode != nullptr) {
            cout << " " << ptrStartingNode->iPayload;
            traversePreOrder(ptrStartingNode->ptrLeft);
            traversePreOrder(ptrStartingNode->ptrRight);
        }
    }

    template<typename T>
    void traverseInOrder(Node<T>* ptrStartingNode) {
        if(ptrStartingNode != nullptr) {
            traverseInOrder(ptrStartingNode->ptrLeft);
            cout << " " << ptrStartingNode->iPayload;
            traverseInOrder(ptrStartingNode->ptrRight);
        }
    }

    template<typename T>
    void traversePostOrder(Node<T>* ptrStartingNode) {
        if(ptrStartingNode != nullptr) {
            traversePostOrder(ptrStartingNode->ptrLeft);
            traversePostOrder(ptrStartingNode->ptrRight);
            cout << " " << ptrStartingNode->iPayload;
        }
    }

}
