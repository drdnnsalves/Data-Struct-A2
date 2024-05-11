#include <iostream>
#include <chrono>
#include <cstdlib> // para srand e rand
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
