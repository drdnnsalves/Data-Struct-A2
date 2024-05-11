#include <iostream>
#include <chrono>
#include <cstdlib> /#include <iostream>
#include <chrono>
#include <cstdlib> // para srand, rand e qsort
#include <ctime>   // para time
#include <cmath> 


using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using namespace std;


struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};
// Functions for LinkedLists
Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void deleteList(Node**);
void listInsertionSort(Node**);

// Functions for Arrays
void printArray(int[], int);
void inserctionSort(int[], int);

int main() {
    srand(time(nullptr));
    
    // Lists size and number of lists
    int iSize = 10000;
    int iNumLists = 100;
    
    double dSumInsertionSort = 0.0;
    double dSumSquaredInsertionSort = 0.0;

    for (int i = 0; i < iNumLists; i++) {
        Node* ptrHeadInsertionSort = nullptr;

        // Criar listas aleatórias
        for (int j = 0; j < iSize; j++) {
            int iValue = rand() % 1000 + 1; // Valor aleatório entre 1 e 1000
            insertEnd(&ptrHeadInsertionSort, iValue);
        }

        // Medir o tempo de execução para Insertion Sort
        auto startInsertionSort = high_resolution_clock::now();
        listInsertionSort(&ptrHeadInsertionSort);
        auto endInsertionSort = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(endInsertionSort - startInsertionSort);
        
        double dTimeInSeconds = timeDuration.count() / 1e9; // Converter para segundos
        dSumInsertionSort += dTimeInSeconds;
        dSumSquaredInsertionSort += dTimeInSeconds * dTimeInSeconds;

        deleteList(&ptrHeadInsertionSort);
    }

    // Mean for listInsertionSort
    double dMeanInsertionSort = dSumInsertionSort / iNumLists;
   
    // Standard Deviation for listInsertionSort
    double dVarianceInsertionSort = (dSumSquaredInsertionSort / iNumLists) - (dMeanInsertionSort * dMeanInsertionSort);
    double dStdDevInsertionSort = sqrt(dVarianceInsertionSort); 

    cout << "Insertion Sort - mean:               " << dMeanInsertionSort << " segundos" << endl;
    cout << "Insertion Sort - standard deviation:       " << dStdDevInsertionSort << " segundos" << endl;

    return 0;
}

Node* createNode(int iValue) {
    Node* temp = new Node; // Alocação de memória com new
    temp->iPayload = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

void displayList(Node* node) {
    if (node == nullptr) {
        cout << "Lista vazia: não é possível realizar displayList" << endl;
        return;
    }

    cout << "Payload: ";
    while (node != nullptr) {
        cout << node->iPayload << " ";
        node = node->ptrNext;
    }
    cout << endl;
}

void insertEnd(Node** head, int iValue) {
    Node* newNode = createNode(iValue);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;

    temp->ptrNext = newNode;
    newNode->ptrPrev = temp;
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != nullptr) {
        next = current->ptrNext;
        free(current);
        current = next;
    }

    *head = nullptr;
}

void listInsertionSort(Node** head) {
    if (*head == nullptr || (*head)->ptrNext == nullptr) // Lista vazia ou apenas um elemento
        return;

    Node* sorted = nullptr; // Lista ordenada
    Node* current = *head;  // Nó atual

    while (current != nullptr) {
        Node* next = current->ptrNext; // Próximo nó a ser processado
        if (sorted == nullptr || sorted->iPayload >= current->iPayload) {
            // Insere no início da lista ordenada
            current->ptrNext = sorted;
            current->ptrPrev = nullptr;
            if (sorted != nullptr)
                sorted->ptrPrev = current;
            sorted = current;
        } else {
            // Procura a posição correta na lista ordenada
            Node* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload)
                temp = temp->ptrNext;
            // Insere o nó após temp
            current->ptrNext = temp->ptrNext;
            current->ptrPrev = temp;
            if (temp->ptrNext != nullptr)
                temp->ptrNext->ptrPrev = current;
            temp->ptrNext = current;
        }
        current = next; // Avança para o próximo nó
    }

    // Atualiza a cabeça da lista
    *head = sorted;
}

void printArray(int arriNumbers[], int iLenght) {
    for(int i = 0; i < iLenght; i++) cout<<arriNumbers[i] << " ";
    cout << endl;
}

void inserctionSort(int arriNumbers[], int iLenght)
{
    int iInsertValue = 0; 
    int iInnerLoop = 0;
    
    for (int iOuterLoop = 1; iOuterLoop < iLenght; iOuterLoop++)
    {
        iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;
        
        while (iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0)
        {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }
        arriNumbers[iInnerLoop + 1] = iInsertValue;

    }
}/ para srand e rand
#include <ctime>   // para time

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void listInsertionSort(Node**); // Corrigido o nome da função

int main() {
    srand(time(nullptr)); // Seed para números aleatórios

    // Tamanhos das listas a serem testadas
    int iSizes[] = {1000, 5000, 10000, 15000};

    cout << "Teste para algoritmo insertionSort" << endl << endl;

    for (int iSize : iSizes) {
        Node* head = nullptr;

        // Criar listas aleatórias
        for (int i = 0; i < iSize; i++) {
            int iValue = rand() % 1000 + 1; // Valor aleatório entre 1 e 1000
            insertEnd(&head, iValue);
        }

        // Medir o tempo de execução para insertionSort
        auto timeStart = high_resolution_clock::now();
        listInsertionSort(&head);
        auto timeEnd = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeEnd - timeStart);
        cout << "Tempo para insertionSort com lista de tamanho " << iSize << ": " << timeDuration.count() << " nanosegundos" << endl;

        // Liberar a memória alocada para a lista
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->ptrNext;
            delete temp;
            temp = next;
        }
    }
    return 0;
}

Node* createNode(int iValue) {
    Node* temp = new Node; // Alocação de memória com new
    temp->iPayload = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

void displayList(Node* node) {
    if (node == nullptr) {
        cout << "Lista vazia: não é possível realizar displayList" << endl;
        return;
    }

    cout << "Payload: ";
    while (node != nullptr) {
        cout << node->iPayload << " ";
        node = node->ptrNext;
    }
    cout << endl;
}

void insertEnd(Node** head, int iValue) {
    Node* newNode = createNode(iValue);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;

    temp->ptrNext = newNode;
    newNode->ptrPrev = temp;
}

void listInsertionSort(Node** head) {
    if (*head == nullptr || (*head)->ptrNext == nullptr) // Lista vazia ou apenas um elemento
        return;

    Node* sorted = nullptr; // Lista ordenada
    Node* current = *head;  // Nó atual

    while (current != nullptr) {
        Node* next = current->ptrNext; // Próximo nó a ser processado
        if (sorted == nullptr || sorted->iPayload >= current->iPayload) {
            // Insere no início da lista ordenada
            current->ptrNext = sorted;
            current->ptrPrev = nullptr;
            if (sorted != nullptr)
                sorted->ptrPrev = current;
            sorted = current;
        } else {
            // Procura a posição correta na lista ordenada
            Node* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload)
                temp = temp->ptrNext;
            // Insere o nó após temp
            current->ptrNext = temp->ptrNext;
            current->ptrPrev = temp;
            if (temp->ptrNext != nullptr)
                temp->ptrNext->ptrPrev = current;
            temp->ptrNext = current;
        }
        current = next; // Avança para o próximo nó
    }

    // Atualiza a cabeça da lista
    *head = sorted;
}
