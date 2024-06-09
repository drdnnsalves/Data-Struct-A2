#include <iostream>
#include <cstdlib>
#include "functionsTree.h"

using namespace std;
using namespace TreeFunctions;

int main() {
    Node<int>* ptrRoot = nullptr;

    ptrRoot = insertNode(ptrRoot, 42);
    ptrRoot = insertNode(ptrRoot, 13);
    ptrRoot = insertNode(ptrRoot, 11);
    ptrRoot = insertNode(ptrRoot, 10);
    ptrRoot = insertNode(ptrRoot, 28);
    ptrRoot = insertNode(ptrRoot, 51);
    ptrRoot = insertNode(ptrRoot, 171);

    cout << "Finding number 51 with traversePreOrder: ";
    traversePreOrder(ptrRoot, 51);
    cout << endl;

    cout << "Finding number 51 with traverseInOrder: ";
    traverseInOrder(ptrRoot, 51);
    cout << endl;

    cout << "Finding number 51 with traversePostOrder: ";
    traversePostOrder(ptrRoot, 51);
    cout << endl;


    return 0;
}
