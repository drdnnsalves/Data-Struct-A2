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

    cout << "Tree Height: " << treeHeight(ptrRoot) << endl;

    cout << "BFS Traversal: ";
    bfsTraversal(ptrRoot);
    cout << endl;

    cout << "Tree Height: " << treeHeight(ptrRoot) << endl;

    return 0;
}
