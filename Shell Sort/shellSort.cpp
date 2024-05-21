#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include "functionsShell.h"

int main() {
    srand(time(nullptr));
    ShellFunctions::Node<int>* ptrShell = nullptr;

    // Cria a lista
    for (int j = 0; j < 10; j++) {
        int value = rand() % 100;
        ShellFunctions::insertEnd(&ptrShell, value);
    }

    cout << "ShellSort is an efficient sorting algorithm that is a generalization of insertion sort. It was invented by Donald Shell in 1959." << endl;
    cout << "To understand the concept of the ShellSort algorithm, one must understand the concept of 'gap'." << endl;
    cout << " A 'gap' is a sequence of numbers created during the execution of the code. There are various ways to construct this sequence." << endl; 
    cout << "Some people use the sequence proposed by Shell: (n/2, n/2, ...), where 'n' is the size of the list."<< endl;
    cout << "Some use proposed by Hibbard: (2^{k} - 1)." << endl;
    cout << "We are going to use the one proposed by Knuth: ( (3^(k) -1)/2 )." << endl;
    cout << "Our sequence of gaps is of the form: (1, 4, 13, 40, 121, ...)" << endl << endl;
    cout << "Here goes a sorting of a list of size 10" << endl << endl << endl;


    cout << "List before sorting: " << endl;
    ShellFunctions::displayList(ptrShell);
    cout << endl;

    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;

    ShellFunctions::shellSort(ptrShell, 10);
    ShellFunctions::displayList(ptrShell);

    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;

    cout << "List sorted: " << endl << endl;
    ShellFunctions::displayList(ptrShell);
    cout << endl << endl;

    cout << "Our first Gap was 4. We go to position (Gap + 1) of the List and switch positions with the position 1."<< endl;
    cout << "If the Value of the Node in position (Gap + 1) is greater, we do the swap and go 1 node front." << endl;
    cout << "After doing this, we reduce the value of the Gap. In our example, we go to Gap = 1." << endl;
    cout << "We do the same. Go to position (Gap + 1), do th eswap with the value behind, and go one front." << endl;
    cout << "Observation: With Gap = 1, we have InsertionSort."<< endl;


    ShellFunctions::deleteList(&ptrShell);

    return 0;
}
