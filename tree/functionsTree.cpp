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
    void bfsTraversal(Node<T>* ptrStartingNode, T value) {
        if (ptrStartingNode == nullptr)
            return;

        Node<T>* ptrFront = nullptr;
        Node<T>* ptrRear = nullptr;

        ptrRear = ptrFront = ptrStartingNode;

        while(ptrFront != nullptr) {
            if(ptrFront->payload == value) {
                cout << "Number " << value << " is in the tree!" << endl;
                return;
            }

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
    bool traversePreOrder(Node<T>* ptrStartingNode, T value) {
        if(ptrStartingNode != nullptr) {
            if(ptrStartingNode->payload == value) {
                cout << "Number " << value << " is in the tree!" << endl;
                return true;
            }

            if (traversePreOrder(ptrStartingNode->ptrLeft, value))
                return true;
            if (traversePreOrder(ptrStartingNode->ptrRight, value))
                return true;
        }
        return false;
    }

    template<typename T>
    bool traverseInOrder(Node<T>* ptrStartingNode, T value) {
        if(ptrStartingNode != nullptr) {
            if (traverseInOrder(ptrStartingNode->ptrLeft, value))
                return true;

            if(ptrStartingNode->payload == value) {
                cout << "Number " << value << " is in the tree!" << endl;
                return true;
            }

            if (traverseInOrder(ptrStartingNode->ptrRight, value))
                return true;
        }
        return false;
    }

    template<typename T>
    bool traversePostOrder(Node<T>* ptrStartingNode, T value) {
        if(ptrStartingNode != nullptr) {
            if (traversePostOrder(ptrStartingNode->ptrLeft, value))
                return true;
            if (traversePostOrder(ptrStartingNode->ptrRight, value))
                return true;

            if(ptrStartingNode->payload == value) {
                cout << "Number " << value << " is in the tree!" << endl;
                return true;
            }
        }
        return false;
    }

}
