#ifndef EVENTOS_H
#define EVENTOS_H


struct Evento 
{

    int instanteDeTempo;   // Tempo do evento 
    string acontecimento;  // Descrição do evento
    // posso fazer um codigo de registro, para facilitar a leitura pelo codigo
    // assim, ao inves de ler o acontecimente, ele iria ler o codigo do acontecimento
    int indetifica;        // codigo de registro do acontecimento

};
    //
    //
    //
    //
    //
    //
    //
    //modelo de impressao
    //cout << "Tempo: " << currentTime << " - Processo " << processo->id << " chegou na CPU" << endl;
#endif
