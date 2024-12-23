#include <iostream>
#include "SimpleMemoryManager.h"
using namespace std;

// Construtor
SimpleMemoryManager::SimpleMemoryManager(int size) : size(size) {
    memory = new int[size];
    for (int i = 0; i < size; ++i) {
        memory[i] = 0; // Inicializar todos os blocos de memória com 0
    }
}

// Destrutor
SimpleMemoryManager::~SimpleMemoryManager() {
    delete[] memory; // Liberar a memória alocada
}

// Alocar memória
int SimpleMemoryManager::alloc(int n) {
    for (int i = 0; i <= size - n; ++i) {
        bool can_allocate = true;
        for (int j = 0; j < n; ++j) {
            if (memory[i + j] != 0) {
                can_allocate = false;
                break;
            }
        }
        if (can_allocate) {
            for (int j = 0; j < n; ++j) {
                memory[i + j] = 1;
            }
            return i; // Retornar o índice inicial da alocação
        }
    }
    return -1; // Falha na alocação
}

// Liberar memória
void SimpleMemoryManager::free(int start, int n) {
    if (start < 0 || start + n > size) {
        cerr << "Erro: Tentativa de liberar memória fora dos limites." << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        memory[start + i] = 0;
    }
}

// Exibir memória
void SimpleMemoryManager::show_memory() const {
    for (int i = 0; i < size; ++i) {
        cout << memory[i];
    }
    cout << endl;
}
