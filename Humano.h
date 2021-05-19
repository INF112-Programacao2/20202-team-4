#ifndef HUMANO_H
#define HUMANO_H

#include "Entidades.h"

class Humano: public Entidades{
public:
  	Humano(std::string nome, int pontos);
	
	int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) override;
	
	~Humano();
};

#endif