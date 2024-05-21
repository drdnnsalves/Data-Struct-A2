#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functionsBubble.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;

    for (int i = 0; i < iNumLists; ++i) {
        BubbleFunctions::Node<int>* ptrBubble = nullptr;
        BubbleFunctions::Node<int>* ptrOptBubble = nullptr;

        // Create Lists
        for (int j = 0; j < iSize; j++) {
            int value = rand() % 100;
            BubbleFunctions::insertEnd(&ptrBubble, value);
            BubbleFunctions::insertEnd(&ptrOptBubble, value);
        }

        // Execution times for listBubbleSort
        auto startBubbleSort = chrono::high_resolution_clock::now();
        BubbleFunctions::listBubbleSort(&ptrBubble, iSize);
        auto endBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationBubbleSort = endBubbleSort - startBubbleSort;

        // Execution times for optimizedListBubbleSort
        auto startOptBubbleSort = chrono::high_resolution_clock::now();
        BubbleFunctions::optimizedListBubbleSort(&ptrOptBubble, iSize);
        auto endOptBubbleSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationOptBubbleSort = endOptBubbleSort - startOptBubbleSort;

        // Printing execution times
        cout << "listBubbleSort, list number " << i << ":  " << durationBubbleSort.count() << " seconds";
        cout << " // optimizedListBubbleSort, list number "<< i << ":" << durationOptBubbleSort.count() << " seconds" << endl;

        BubbleFunctions::deleteList(&ptrBubble);
        BubbleFunctions::deleteList(&ptrOptBubble);
    }
    return 0;
}

