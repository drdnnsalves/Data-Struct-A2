#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functions.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    for (int i = 0; i < iNumLists; ++i) {
        Node* ptrSelection = nullptr;
        Node* ptrOptSelection = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int iValue = rand() % 100;
            insertEnd(&ptrSelection, iValue);
            insertEnd(&ptrOptSelection, iValue);
        }

        // Execution times for listSelectionSort
        auto startBubbleSort = chrono::high_resolution_clock::now();
        listSelectionSort(&ptrSelection, iSize);
        auto endBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationBubbleSort = endBubbleSort - startBubbleSort;

        // Execution times for optimizedListSelectionSort
        auto startOptBubbleSort = chrono::high_resolution_clock::now();
        optimizedListSelectionSort(&ptrOptSelection, iSize);
        auto endOptBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationOptBubbleSort = endOptBubbleSort - startOptBubbleSort;

        // Printing execution times
        cout << "listSelectionSort, list number " << i << ":  " << durationBubbleSort.count() << " seconds";
        cout << " // optimizedListSelectionSort, list number "<< i << ":" << durationOptBubbleSort.count() << " seconds" << endl;

        deleteList(&ptrSelection);
        deleteList(&ptrOptSelection);
    }
    return 0;
}
