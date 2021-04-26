#ifndef CARTAS_H
#define CARTAS_H

class Cartas{
private:
	int numero, naipe;
	bool especial;
public:
	Cartas(int numero, int naipe);
	void imprimeCarta();
};

#endif