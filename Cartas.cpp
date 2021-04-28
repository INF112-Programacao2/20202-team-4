#include <iostream>
#include <string>
#include "Cartas.h"

Cartas::Cartas(int numero, int naipe):numero(numero), naipe(naipe){
	if((this->numero == 4 && this->naipe == 4) ||
	   (this->numero == 7 && this->naipe == 3) ||
	   (this->numero == 1 && this->naipe == 2) ||
	   (this->numero == 7 && this->naipe == 1)) this->especial = true;
	else this->especial = false;
}

void Cartas::imprimeCarta(){
	std::string valoresDasCartas = "A23456789 QJK";
	std::string naipes[4] = {"o", "e", "c", "p"};
	this->numero == 10 ? std::cout << 10 : std::cout << valoresDasCartas[this->numero-1];
	std::cout << naipes[this->naipe-1];
}