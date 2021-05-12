#ifndef JOGADA_H
#define JOGADA_H

#include <vector>
#include "Baralho.h"

class Jogada{
private:
    int rodada;
    int turno;
    bool turnoInicial;
    int jogadorInicial;
    Baralho baralho;
    std::vector<Entidades*> jogadores;

public:
    Jogada(); //sem parametros momentaneamente 
    int get_rodada();
    int get_turno();
    void adicionaJogador();
    void distribuirCartas();
    void mudaTurno();
    void mudaJogadorInicial();
    void jogaTurno();
};

#endif
