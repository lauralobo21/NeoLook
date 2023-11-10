/*
    Nome dos integrantes da dupla:
        Hugo das Chagas Silva - 553635
        Laura Soléria Lobo Vitorino Maciel - 555523
*/



// NÃO NECESSÁRIA PARA A PRIMEIRA PARTE DO PROJETO


#include <iostream>
#include <vector>
#include <fstream> //Para ler e escrever arquivos .txt
#include <cstdlib>
#include <ctime>
#include "Eventos.h"
#include "Processos.h"
#include "Comp.h"

using namespace std;


int main( ){
    int qtdComp;
    string dados;
        cout << "Digite a quantidade de computadores: " << endl;
        cin >> qtdComp;

        RegistroEventos registro;
    
    //
    //Apartir daqui eu leio o arquivo .txt e armazeno os dados.
    //
    
    cin >> dados;
    ifstream arquivo(dados+".txt");
    // Adicione os dados de processo na struct Process
    vector< Process > baseProcessos;     
    
    int TotalInst = 0;
    if (arquivo.is_open()) {
        Process processo;
        // Loop para ler os dados do arquivo e armazená-los no vetor
        int processoId = 1;
        while (arquivo >> processo.Instante >> processo.TempoCPU >> processo.TempoDisco >> processo.TempoRede) {
            // Atribui o ID do processo sequencialmente
                processo.id = processoId; 
            // Define o ID do computador, tempo de espera e tempo de execução como -1 (nulo) inicialmente
                processo.ComputadorId = -1;
                processo.TempoDeEsp = -1;
                processo.TempoDeExe = -1;
                processo.terminado = false;
                baseProcessos.push_back(processo);
            // Incrementa o ID do processo para o próximo processo
                ++processoId;
            //TotalInstante recebe o ultimo instante de execução
                TotalInst = processo.Instante;
        }
        arquivo.close(); // Fecha o arquivo após a leitura
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1; // Retorna um código de erro se o arquivo não puder ser aberto
    }

        //
        //Apartir daqui eu começo a distribuir os processos de forma aleatoria nos computadores
        //

    // Inicializa a semente para geração de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    vector< Computador > Computadores(qtdComp);

    // Adiciona processos aleatoriamente aos computadores usando ponteiros para Process
    for (const auto& processoDados : baseProcessos) {
        // Gera um número aleatório de 0 a 999 para definir qual computador ira receber o processo.
        // Escolhe um computador aleatório para adicionar o processo
        int computadorIdentidade = rand() % qtdComp; 
        
        // Aloca dinamicamente um novo processo
        Process* novoProcesso = new Process;
        
        // Atribui os valores do processo lido do arquivo aos campos do novo processo
        novoProcesso->id = processoDados.id;
        novoProcesso->Instante = processoDados.Instante;
        novoProcesso->TempoCPU = processoDados.TempoCPU;
        novoProcesso->TempoDisco = processoDados.TempoDisco;
        novoProcesso->TempoRede = processoDados.TempoRede;
        novoProcesso->ComputadorId = computadorIdentidade; // Define o ID do computador que foi atribuido   
        // Adiciona o novo processo ao computador usando o ponteiro
        Computadores[computadorIdentidade].addProcess(novoProcesso);
    }

    //
    //Apartir daqui começa a execução da simulação
    //

    const int InstMax = TotalInst;
    for (int InstanteExato = 0; InstanteExato < InstMax; ++InstanteExato) {
        cout << "Tempo: " << InstanteExato << endl;
        for (auto& computador : Computadores) {
            computador.executeCPU(InstanteExato);
        }
    }

    return 0;
}
