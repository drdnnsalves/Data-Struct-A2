#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <queue>
#include "functionsTree.h"

using namespace std;
using namespace TreeFunctions;

int main() {
    // Constantes
    const int size = 10000;
    const int repetitions = 1000;

    // Arrays para armazenar os tempos de execução
    double times_create_list[repetitions];
    double times_search_list[repetitions];
    double times_create_tree[repetitions];
    double times_search_bfs[repetitions];
    double times_search_dfs[repetitions];

    for (int i = 0; i < repetitions; ++i) {
        // Creating list with specified size
        auto start_create_list = chrono::high_resolution_clock::now();
        int* list = new int[size];
        for (int j = 0; j < size; ++j) {
            list[j] = rand() % size;
        }
        auto end_create_list = chrono::high_resolution_clock::now();
        times_create_list[i] = chrono::duration_cast<chrono::nanoseconds>(end_create_list - start_create_list).count();

        // Searching the list
        int search_value = rand() % size;
        auto start_search_list = chrono::high_resolution_clock::now();
        for (int j = 0; j < size; ++j) {
            if (list[j] == search_value)
                break;
        }
        auto end_search_list = chrono::high_resolution_clock::now();
        times_search_list[i] = chrono::duration_cast<chrono::nanoseconds>(end_search_list - start_search_list).count();

        // Creating tree with specified size
        auto start_create_tree = chrono::high_resolution_clock::now();
        Node<int>* ptrRoot1 = nullptr; 
        for (int j = 0; j < size; ++j) {
            ptrRoot1 = insertNode(ptrRoot1, rand() % size);
        }
        auto end_create_tree = chrono::high_resolution_clock::now();
        times_create_tree[i] = chrono::duration_cast<chrono::nanoseconds>(end_create_tree - start_create_tree).count();

        // Searching the tree with BFS
        auto start_search_bfs = chrono::high_resolution_clock::now();
        bfsTraversal(ptrRoot1, search_value);
        auto end_search_bfs = chrono::high_resolution_clock::now();
        times_search_bfs[i] = chrono::duration_cast<chrono::nanoseconds>(end_search_bfs - start_search_bfs).count();

        // Searching the tree with DFS
        auto start_search_dfs = chrono::high_resolution_clock::now();
        traversePreOrder(ptrRoot1, search_value);
        auto end_search_dfs = chrono::high_resolution_clock::now();
        times_search_dfs[i] = chrono::duration_cast<chrono::nanoseconds>(end_search_dfs - start_search_dfs).count();

        // Freeing memory allocated to the list and tree
        free(list);
        free(ptrRoot1); // Assumindo que você tenha uma função para liberar a árvore
    }

    // Escrevendo todos os tempos no arquivo result.txt
    ofstream result_file("Times.txt");
    if (result_file.is_open()) {
        result_file << "Iteration\tCreate and Search List (ns)\t\t\t\tCreate and Search Tree (ns)" << endl;
        for (int i = 0; i < repetitions; ++i) {
            result_file << i + 1 << "\t\t\t\t\t\t" 
                        << times_create_list[i] + times_search_list[i]<< "\t\t\t\t\t\t" 
                        << times_create_tree[i] + times_search_bfs[i] + times_search_dfs[i]<< endl;

        }
        result_file.close();
        } else {
        cout << "Error opening the file result.txt" << endl;
    }

    return 0;
}
