#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <string>
#include <vector>
#include "Jogada.h"
#include "Cartas.h"

class Entidades{
protected:
	std::string nome; 
	int pontos;
	std::vector<Cartas> cartas;

public:
	Entidades(std::string nome, int pontos);
	
	std::string get_nome();
	int get_pontos();
	
	void adicionaCarta(Cartas cartaParaAdicionar);
	virtual int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) = 0;
};

#endif