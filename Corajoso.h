#ifndef CORAJOSO_H
#define CORAJOSO_H

#include "Entidades.h"

class Corajoso:public Entidades{
public:
	Corajoso(std::string nome, int pontos);
	
	int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) override;
	
	~Corajoso();
};

#endif