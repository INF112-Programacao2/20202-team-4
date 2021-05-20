#ifndef JOGADA_H
#define JOGADA_H

#include <iostream>
#include <vector>
#include <string>
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
	bool sobeRodada;
	bool rodaJogo;
	int rodada;
	int turno;
	int jogadorInicialRodada;
	int jogadorInicialTurno;
	std::vector<Entidades*> jogadores;
	std::vector<Cartas> cartasJogadas;
	
public:
	Jogada(std::string nomeUsuario);
	~Jogada();
	int get_rodada();
	int get_turno();
	bool get_rodaJogo();
	void distribuirCartas();
	void determinaVencedorTurno();
	void jogaTurno();
	void analiseRodada();
	void mudaTurno();
	void mudaJogadorInicial();
	void imprimeVidas();
};

#endif