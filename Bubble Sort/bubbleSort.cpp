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
        Node* ptrBubble = nullptr;
        Node* ptrOptBubble = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int value = rand() % 100;
            insertEnd(&ptrBubble, value);
            insertEnd(&ptrOptBubble, value);
        }

        // Execution times for listBubbleSort
        auto startBubbleSort = chrono::high_resolution_clock::now();
        listBubbleSort(&ptrBubble, iSize);
        auto endBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationBubbleSort = endBubbleSort - startBubbleSort;

        // Execution times for optimizedListBubbleSort
        auto startOptBubbleSort = chrono::high_resolution_clock::now();
        optimizedListBubbleSort(&ptrOptBubble, iSize);
        auto endOptBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationOptBubbleSort = endOptBubbleSort - startOptBubbleSort;

        // Printing execution times
        cout << "listBubbleSort, list number " << i << ":  " << durationBubbleSort.count() << " seconds";
        cout << " // optimizedListBubbleSort, list number "<< i << ":" << durationOptBubbleSort.count() << " seconds" << endl;

        deleteList(&ptrBubble);
        deleteList(&ptrOptBubble);
    }
    return 0;
}

