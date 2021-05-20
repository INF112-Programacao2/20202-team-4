#ifndef CARTAS_H
#define CARTAS_H

#include <vector>

class Cartas{
private:
	int numero, naipe;
	bool ehCartaEspecial;

public:
	Cartas(int numero, int naipe);
	
	int get_numero();
	int get_naipe();
	bool get_ehCartaEspecial();
	
	void imprimeCarta();
	~Cartas();
};

#endif