#include "functionsTree.h"
#include <iostream>

using namespace std;

namespace TreeFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = new Node<T>;

        if(ptrTemp == nullptr) {
            cerr << "Error in createNode: memory allocation failed" << endl;
            exit(1);
        } 

        ptrTemp->payload = value;
        ptrTemp->ptrLeft = nullptr;
        ptrTemp->ptrRight = nullptr;
        ptrTemp->next = nullptr;

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

        Node<T>* front = nullptr;
        Node<T>* rear = nullptr;

        rear = front = ptrStartingNode;

        while (front != nullptr) {
            cout << front->payload << " ";

            if (front->ptrLeft != nullptr) {
                rear->next = front->ptrLeft;
                rear = rear->next;
            }
            if (front->ptrRight != nullptr) {
                rear->next = front->ptrRight;
                rear = rear->next;
            }

            front = front->next;
        }
    }

}
