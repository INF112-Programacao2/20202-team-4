#ifndef CALCULISTA_H
#define CALCULISTA_H

#include "Entidades.h"

class Calculista:public Entidades{
public:
	Calculista(std::string nome, int pontos);
	int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) override;
};

#endif
