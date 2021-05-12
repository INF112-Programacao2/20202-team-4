#ifndef JOGADA_H
#define JOGADA_H

#include <vector>
#include "Baralho.h"
#include "Entidades.h"

class Jogada{
private:
    int rodada;
    int turno;
    bool turnoInicial;
    int jogadorInicialRodada;
    int jogadorInicialTurno;
    Baralho baralho;
    std::vector<Entidades*> jogadores;
    std::vector<Cartas> cartasJogadas;

public:
    Jogada(); //sem parametros momentaneamente
    ~Jogada();
    int get_rodada();
    int get_turno(); 
    void distribuirCartas(); //turno == numero de cartas pra cada jogador   
    void determinaVencedorTurno(); //cartasJogadas
    void jogaTurno(); //std::vector<Entidades*> jogadores são chamados pra fazer as jogadas, armazenadas em cartasJogadas, parametro de determinaVencedorTurno()
    void mudaTurno(); //turno++, if(turno==rodada) turno = 0 bool turnoInicial == true
    void mudaJogadorInicial(); //if(turnoInicial = true) jogadorInicialRodada++, else jogadorInicialTurno == ganhador anterior
};

#endif
