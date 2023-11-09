#ifndef PROCESSOS_H
#define PROCESSOS_H

struct Process 
{
    int id;             // ID do processo
    int Instante;        // Tempo de início da execução do processo
    int TempoCPU;       // Tempo de CPU necessário para o processo
    int instanteDeDisco;
    int TempoDisco;     // Tempo de disco necessário para o processo
    int instanteDeRede;
    int TempoRede;      // Tempo de rede necessário para o processo
    int ComputadorId;   // ID do computador onde o processo está sendo executado
    int TempoDeEsp;
    int TempoDeExe;
    bool terminado;
};

#endif // PROCESSOS_H
