#include "functionsTree.h"
#include <cstdlib>

using namespace std;

namespace TreeFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = (Node<T>*) malloc(sizeof(Node<T>));

        if(ptrTemp == nullptr) {
            cerr << "Error in creatNode: malloc" << endl;
            exit(1);
        } 

        ptrTemp->payload = value;
        ptrTemp->ptrLeft = nullptr;
        ptrTemp->ptrRight = nullptr;
    }

    template<typename T>
    Node<T>* insertNode(Node<T>* startNode, T value) {
        if (startNode == nullptr) {
            return createNode(value);
        }
        if (value< startNode -> payload) {
            startNode -> ptrLeft = insertNode(startNode -> ptrLeft, value); 
        }
        else {
            startNode -> ptrRight = insertNode(startNode -> ptrRight, value); 
        }

        return startNode; 
    }

    template<typename T>
    int treeHeight(Node<T>* ptrStartingNode) {
        if(ptrStartingNode == nullptr)
            return 0;
        else {
            int iLeftHeight = treeHeight(ptrStartingNode->ptrLeft);
            int iRightHeight = treeHeight(ptrStartingNode->ptrRight);

            return max(iLeftHeight, iRightHeight) + 1;
        }
    }

    template<typename T>
    void bfsTraversal(Node<T>* ptrStartingNode) {
    if(ptrStartingNode == nullptr)
        return;

        // Parte 1: Alterar para lista encadeada
        Node<T>* nodeQueue[100];
        int iQueueFront = 0;
        int iQueueRear = 0;

        nodeQueue[iQueueRear] = ptrStartingNode;
        iQueueRear++;

        while(iQueueFront < iQueueRear) {
            Node<T>* currentNode = nodeQueue[iQueueFront];
            iQueueFront++;

            cout << currentNode->payload << " ";

            if(currentNode->ptrLeft != nullptr) {
                nodeQueue[iQueueRear] = currentNode->ptrLeft;
                iQueueRear++;
            }

            if(currentNode->ptrRight != nullptr) {
                nodeQueue[iQueueRear] = currentNode->ptrRight;
                iQueueRear++;
            }
        }
    }   


}