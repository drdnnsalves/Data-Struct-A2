#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functionsTree.h"

int main() {
    TreeFunctions::Node<int>* ptrRoot = nullptr;

    ptrRoot = TreeFunctions::insertNode(ptrRoot, 42);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 13);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 11);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 10);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 28);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 51);
    ptrRoot = TreeFunctions::insertNode(ptrRoot, 171);

    cout << "BFS Traversal: ";
    TreeFunctions::bfsTraversal(ptrRoot);
    cout << endl;

    cout << "Tree Height: ";
    cout << TreeFunctions::treeHeight(ptrRoot);
    cout << endl;


    return 0;
}
// Parte 2: Elaborar busca utilizando BFS (Ja foi feito DFS)
// Parte 3: Monitorar tempo de busca de arvore usando BFS e DFS
// Parte 4: Monitorar o desempenho de criação de listas com 10000 elementos
// Parte 5: Monitorar o desempenho de criação de arvores com 10000 elementos



