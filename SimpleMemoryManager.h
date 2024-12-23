#ifndef SIMPLEMEMORYMANAGER_H
#define SIMPLEMEMORYMANAGER_H

class SimpleMemoryManager {
private:
    int* memory;    // Ponteiro para representar a memória
    int size;       // Tamanho total da memória

public:
    // Construtor
    SimpleMemoryManager(int size);

    // Destrutor
    ~SimpleMemoryManager();

    // Método para alocar memória
    int alloc(int n);

    // Método para liberar memória
    void free(int start, int n);

    // Método para exibir a memória
    void show_memory() const;
};

#endif 
