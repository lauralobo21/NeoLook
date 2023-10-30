/*
    Nome dos integrantes da dupla:
        Hugo das Chagas Silva - 553635
        Laura Soléria Lobo Vitorino Maciel - 555523
*/

#include <iostream>
#include "Priority_queue.h"
using namespace std;

int main() {
    // Criando um vetor com elementos em ordem inversa
    int v[] = {5, 4, 3, 2, 1};

    // Criando uma priority queue do tipo int
    PriorityQueue<int> filaOrdenada;
    for (int i = 0; i < 5; ++i) {
        // Inserindo elementos do vetor na fila ordenada
        filaOrdenada.push(v[i]);
    }

    // Imprimindo o elemento do topo da fila de prioridades
    cout << filaOrdenada.top() << endl;

    // Imprimindo o tamanho da fila de prioridades
    cout << filaOrdenada.size() << endl;

    // Removendo o elemento com maior prioridade
    filaOrdenada.pop();
    cout << filaOrdenada.top() << endl;

    // Destruindo
    filaOrdenada.~PriorityQueue();

}
