/*
    Nome dos integrantes da dupla:
        Hugo das Chagas Silva - 553635
        Laura Soléria Lobo Vitorino Maciel - 555523
*/


//  NÃO NECESSÁRIA PARA A PRIMEIRA PARTE DO PROJETO


#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include <iostream>
#include <vector>
#include <random>
#include "Queue.h"
#include "Priority_queue.h"
#include "Processos.h"

using namespace std;

class Computador {
private:
    vector< Process* > Processos;
    vector< Evento   > Eventos;    
    Queue<int > CPU;
    Queue<int > Disco1;
    Queue<int > Disco2;
    //PriorityQueue<int > CPUp;
    //PriorityQueue<int > Disco1p;
    //PriorityQueue<int > Disco2p;

public:

    Computador() = default;

    void addProcess( Process* process) {
        Processos.push_back(process);
    }


    bool isFinished() const {
        return CPU.empty() && Disco1.empty() && Disco2.empty();
    }
    
    void executeStep(int currentTime) {
        if(!Processos.empty())
        for (auto processo : Processos) {
            if (processo->Instante == currentTime) {
                //passo para verificar se é o primeiro processo da cpu
                    //if()
                    CPU.push(processo ->TempoCPU);
                
            }
        }
        //refazer a logica
        //implementar a base para a priority_queue
        /*
        random_device rd; // Seed para o gerador de números aleatórios
        mt19937 gen(rd()); // Mersenne Twister engine
        uniform_int_distribution<> dis(0, 1); // Distribuição uniforme para escolher entre os vetores 0 e 
        int escolha = dis(gen); // Escolhe aleatoriamente entre 0 e 1

        if (escolha == 0) {
            Disco1.push(process ->TempoDisco);
        } else {
            Disco2.push(process ->TempoDisco);
        }
        */
        
    }
    
    // Destrutor para liberar a memória alocada dinamicamente
    ~Computador() {
        // Libera a memória de todos os processos alocados dinamicamente
        for (auto processo : Processos) {
            delete processo;
        }
    }




};


#endif
