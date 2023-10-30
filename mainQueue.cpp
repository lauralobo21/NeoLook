/*
    Nome dos integrantes da dupla:
        Hugo das Chagas Silva - 553635
        Laura Soléria Lobo Vitorino Maciel - 555523
*/

#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    // Criando uma queue do tipo string chamada fila
    Queue<string> fila;
    // Adicionando pessoas no arquivo
    fila.push("laura");
    fila.push("hugo");
    fila.push("claudia");
    
    //imprimindo a pessoa na frente da fila
    cout << fila.front() << endl;

    //imprimindo a pessoa no final da fila
    cout << fila.back() << endl;

    //imprimindo a quantidade de pessoas na fila
    cout << fila.size() << endl;

    //removendo a pessoa no começo da fila
    fila.pop();
    cout << fila.front() << endl;

    //destruindo a fila
    fila.~Queue();

}