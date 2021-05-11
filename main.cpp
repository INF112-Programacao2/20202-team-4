#include <iostream>
#include <vector>
#include "Cartas.h"
#include "Baralho.h"
#include "Entidades.h"
#include "Corajoso.h"

int main(){
	Corajoso c("corajosin", 0);
	std::vector<Cartas> cartasJogadas;
	cartasJogadas.push_back(Cartas(7, 1));
	c.adicionaCarta(Cartas(1, 1));
	c.adicionaCarta(Cartas(11, 4));
	c.adicionaCarta(Cartas(7, 2));
	c.adicionaCarta(Cartas(4, 1));
	c.adicionaCarta(Cartas(3, 1));
		
	c.ordenaCartasDaMao();
	for(int i=0; i<5; i++){
		c.imprimeCarta(i);
		std::cout << "\n";
	}
	std::cout << "\n";
	c.imprimeCarta(c.calculaJogada(0, cartasJogadas));
	return 0;
}