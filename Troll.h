#ifndef TROLL_H
#define TROLL_H

#include "Entidades.h"

class Troll:public Entidades{
public:
	Troll(std::string nome, int pontos);
	
	int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) override;	
	
	~Troll();
};

#endif