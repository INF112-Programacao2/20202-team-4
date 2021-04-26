#include <iostream>
#include <string>
#include "Cartas.h"

Cartas::Cartas(int numero, int naipe):numero(numero), naipe(naipe){
	if((numero == 4 && naipe == 4) ||
	   (numero == 7 && naipe == 3) ||
	   (numero == 1 && naipe == 2) ||
	   (numero == 7 && naipe == 1)) this->especial = true;
	else this->especial = false;
}

void Cartas::imprimeCarta(){
	std::string valoresDasCartas = "A23456789 QJK";
	std::string naipes[4] = {"o", "e", "c", "p"};
	this->numero == 10 ? std::cout << 10 : std::cout << valoresDasCartas[this->numero-1];
	std::cout << naipes[this->naipe-1];
}