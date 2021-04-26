#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include "Cartas.h"

class Baralho{
private:
	std::vector<Cartas*> cartaBaralho;
public:
	Baralho();
	~Baralho();
	void embaralhaCartas();
	void imprimeCarta(int pos);
};

#endif