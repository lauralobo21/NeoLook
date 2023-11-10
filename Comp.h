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
#include "Eventos.h"
#include "Queue.h"
#include "Priority_queue.h"
#include "Processos.h"

using namespace std;



class Computador {
private:
    RegistroEventos evento;
    vector< Process* > Processos;    
    Queue < Process* > CPU;
    int esperaCpu = 0;

    Queue < Process* > Disco1;
    int esperaDisco1 = 0, instanteDisco1 = 0;
    
    Queue < Process* > Disco2;
    int esperaDisco2 = 0, instanteDisco2 = 0;

public:

    Computador() = default;

    void addProcess( Process* process) {
        Processos.push_back(process);
    }


    bool isFinished() const {
        return CPU.empty() && Disco1.empty() && Disco2.empty();
    }
    
    void executeCPU(int currentTime) {
        if(!Processos.empty())
        for (auto processo : Processos) {
            if (processo->Instante == currentTime) {
                //passo para verificar se é o primeiro processo da cpu
                    if(CPU.empty()){
                        
                        CPU.push(processo);
                        processo -> TempoDeEsp = 0;      //como nao tem ninguem na fila, entao nao tem tempo de espera.
                        esperaCpu += processo ->TempoCPU;
                    
                    }else{
                    //verificar se o processo que ja esta sendo executado ja terminou
                        if(CPU.front() -> TempoCPU == currentTime - CPU.front() ->TempoDeEsp){
                            
                            esperaCpu -= CPU.front() -> TempoCPU;
                            //atualiza o tempo que chegou ao disco e manda para o disco.
                            CPU.front() ->instanteDeDisco = currentTime;
                            executeDisco( CPU.front(), currentTime );
                            // tira da fila de cpu 
                            CPU.pop();

                        }
                        //apos retirar ou nao, segue o processo normalmente.
                        CPU.push(processo);
                        // verificar o calculo.
                        processo -> TempoDeEsp = esperaCpu - currentTime ;
                        esperaCpu += processo ->TempoCPU;
                    }
            }

        }

    }
    
    void executeDisco (Process* processo, int currentTime){
        //refazer a logica
        //implementar a base para a priority_queue
        
        random_device rd; // Seed para o gerador de números aleatórios
        mt19937 gen(rd()); // Mersenne Twister engine
        uniform_int_distribution<> dis(0, 1); // Distribuição uniforme para escolher entre os vetores 0 e 
        int escolha = dis(gen); // Escolhe aleatoriamente entre 0 e 1

        if ( Disco1.empty() && Disco2.empty( ) ) {
            if (escolha == 0 ) {
                
                Disco1.push(processo);
                processo -> TempoDeEsp += 0;
                esperaDisco1 += processo -> TempoDisco;
                
            } else {
                
                Disco2.push(processo);
                processo -> TempoDeEsp += 0;
                esperaDisco2 += processo -> TempoDisco;

            }

        }else if( !Disco1.empty() && !Disco2.empty( ) ){    
            if (escolha == 0 ) {
                if(Disco1.front() -> TempoDisco <= currentTime - Disco1.front() ->instanteDeDisco ){
                        esperaDisco1 -= Disco1.front() -> TempoDisco;
                        //manda pra rede  
                        Disco1.pop();
                }
                        Disco1.push(processo);
                        // verificar o calculo.
                        processo -> TempoDeEsp = esperaDisco1 - currentTime ;
                        esperaDisco1 += processo ->TempoDisco;
                
            } else {
                if(Disco2.front() -> TempoDisco <= currentTime - Disco2.front() ->instanteDeDisco ){
                        esperaDisco2 -= Disco2.front() -> TempoDisco;
                        //manda pra rede  
                        Disco2.pop();
                }
                        Disco2.push(processo);
                        // verificar o calculo.
                        processo -> TempoDeEsp = esperaDisco2 - currentTime ;
                        esperaDisco2 += processo ->TempoDisco;
            }
        
        }else if(Disco1.empty()){
            Disco1.push(processo);
            processo -> TempoDeEsp += 0;
            esperaDisco1 += processo -> TempoDisco;
            
        }else{
            Disco2.push(processo);
            processo -> TempoDeEsp += 0;
            esperaDisco2 += processo -> TempoDisco;
        }

        
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
