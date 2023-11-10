#include <queue>
#include <iostream>
#include <vector>
#include "Queue.h"
#include "Processos.h" 

using namespace std;

class RedeCompartilhada {

private:
    queue< Process* > filaDeProcessos;
    int esperaRede = 0;

public:
    void adicionarProcesso(Process* processo) {
        filaDeProcessos.push(processo); // Adiciona o processo à fila da rede compartilhada
    }

    void executarPasso(int tempoAtual) {
            /*
        for (auto processo : Processos) {
                //passo para verificar se é o primeiro processo da cpu
                    if(CPU.empty()){
                        
                        CPU.push(processo);
                        processo -> TempoDeEsp = 0;      //como nao tem ninguem na fila, entao nao tem tempo de espera.
                        esperaCpu += processo ->TempoCPU;
                    
                    }else{
                    //verificar se o processo que ja esta sendo executado ja terminou
                        if(CPU.front() -> TempoCPU == currentTime - CPU.front() ->TempoDeEsp){
                            //atualiza o tempo que chegou ao disco e manda para o disco.
                            CPU.front() ->instanteDeDisco = currentTime;
                            executeDisco( CPU.front() );
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
            */
    }
};
