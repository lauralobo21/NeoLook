#include <string>
#include <vector>

using namespace std;

class RegistroEventos {
private:
    struct Evento {
        int tempo;
        string descricao;
    };

    vector<Evento> eventos;

public:
    void registrarEvento(int tempo, const std::string& descricao) {
        eventos.push_back({tempo, descricao});
    }

    void gerarRelatorio() const {
        cout << "Relatório de Eventos:" << std::endl;
        for (const auto& evento : eventos) {
            cout << "Tempo: " << evento.tempo << " - " << evento.descricao << std::endl;
        }
    }
};
