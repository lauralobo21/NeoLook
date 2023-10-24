#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;
struct Process {
    int id;             // ID do processo
    int Istante;        // Tempo de início da execução do processo
    int TempoCPU;       // Tempo de CPU necessário para o processo
    int TempoDisco;     // Tempo de disco necessário para o processo
    int TempoRede;      // Tempo de rede necessário para o processo
    int ComputadorId;   // ID do computador onde o processo está sendo executado
};

struct Eventos {
    int instanteDeTempo;
    string acontecimento;
};

int main( ){
    string tipo;

    cin >> tipo;



    return 0;
}