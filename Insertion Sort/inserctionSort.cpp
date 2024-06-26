#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functionsInsertion.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    for (int i = 0; i < iNumLists; ++i) {
        InsertionFunctions::Node<int>* ptrSelection = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int iValue = rand() % 100;
            InsertionFunctions::insertEnd(&ptrSelection, iValue);
        }

        // Execution times for listInsertionSort
        auto startSelectionSort = chrono::high_resolution_clock::now();
        InsertionFunctions::listInsertionSort(&ptrSelection);
        auto endSelectionSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSelectionSort = endSelectionSort - startSelectionSort;

        // Printing execution times
        cout << "listInsertionSort, list number " << i << ":  " << durationSelectionSort.count() << " seconds" << endl;

        InsertionFunctions::listInsertionSort(&ptrSelection);
        InsertionFunctions::deleteList(&ptrSelection);
    }
    return 0;
}
