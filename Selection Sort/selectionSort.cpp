#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functionsSelection.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    for (int i = 0; i < iNumLists; ++i) {
        SelectionFunctions::Node<int>* ptrSelection = nullptr;
        SelectionFunctions::Node<int>* ptrOptSelection = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int iValue = rand() % 100;
            SelectionFunctions::insertEnd(&ptrSelection, iValue);
            SelectionFunctions::insertEnd(&ptrOptSelection, iValue);
        }

        // Execution times for listSelectionSort
        auto startSelectionSort = chrono::high_resolution_clock::now();
        SelectionFunctions::listSelectionSort(&ptrSelection, iSize);
        auto endSelectionSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSelectionSort = endSelectionSort - startSelectionSort;

        // Execution times for optimizedListSelectionSort
        auto startOptSelectionSort = chrono::high_resolution_clock::now();
        SelectionFunctions::optimizedListSelectionSort(&ptrOptSelection, iSize);
        auto endOptSelectionSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationOptSelectionSort = endOptSelectionSort - startOptSelectionSort;

        // Printing execution times
        cout << "listSelectionSort, list number " << i << ":  " << durationSelectionSort.count() << " seconds";
        cout << " // optimizedListSelectionSort, list number "<< i << ":" << durationOptSelectionSort.count() << " seconds" << endl;

        SelectionFunctions::deleteList(&ptrSelection);
        SelectionFunctions::deleteList(&ptrOptSelection);
    }
    return 0;
}
