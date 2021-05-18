#ifndef JOGADA_H
#define JOGADA_H

#include <iostream>
#include <vector>
#include "Baralho.h"
#include "Entidades.h"
#include "Troll.h"
#include "Humano.h"
#include "Corajoso.h"
#include "Calculista.h"

class Jogada{
private:
	Baralho baralho;
	bool turnoInicial;
	int rodada;
	int turno;
	int jogadorInicialRodada;
	int jogadorInicialTurno;
	std::vector<Entidades*> jogadores;
	std::vector<Cartas> cartasJogadas;
	
public:
	Jogada();
	~Jogada();
	int get_rodada();
	int get_turno();
	void distribuirCartas();
	void determinaVencedorTurno();
	void jogaTurno();
	void mudaTurno();
	void mudaJogadorInicial();
};

#endif