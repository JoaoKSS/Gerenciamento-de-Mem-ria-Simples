#include <iostream>
#include "SimpleMemoryManager.h"
using namespace std;

int main() {
    // Cria um gerenciador de memória com 20 bytes
    SimpleMemoryManager manager(20);

    cout << "Memória Inicial: ";
    manager.show_memory();

    // Alocar 5 bytes
    cout << "\nTentando alocar 5 bytes..." << endl;
    int idx1 = manager.alloc(5);
    if (idx1 != -1) {
        cout << "Alocação bem-sucedida, começando no índice " << idx1 << endl;
    } else {
        cout << "Alocação falhou." << endl;
    }
    cout << "Memória: ";
    manager.show_memory();

    // Alocar 8 bytes
    cout << "\nTentando alocar 8 bytes..." << endl;
    int idx2 = manager.alloc(8);
    if (idx2 != -1) {
        cout << "Alocação bem-sucedida, começando no índice " << idx2 << endl;
    } else {
        cout << "Alocação falhou." << endl;
    }
    cout << "Memória: ";
    manager.show_memory();

    // Liberar 5 bytes a partir do índice 0
    cout << "\nLiberando 5 bytes a partir do índice 0..." << endl;
    manager.free(0, 5);
    cout << "Memória: ";
    manager.show_memory();

    // Alocar 5 bytes novamente
    cout << "\nTentando alocar 5 bytes novamente..." << endl;
    int idx3 = manager.alloc(5);
    if (idx3 != -1) {
        cout << "Alocação bem-sucedida, começando no índice " << idx3 << endl;
    } else {
        cout << "Alocação falhou." << endl;
    }
    cout << "Memória: ";
    manager.show_memory();

    return 0;
}
