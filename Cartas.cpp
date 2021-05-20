#include <iostream>
#include <string>
#include "Cartas.h"

Cartas::Cartas(int numero, int naipe):numero(numero), naipe(naipe){ 
	if((this->numero == 4 && this->naipe == 4) || //Procura as 4 cartas especiais para "marcá-las"
	   (this->numero == 7 && this->naipe == 3) ||
	   (this->numero == 1 && this->naipe == 2) ||
	   (this->numero == 7 && this->naipe == 1)) this->ehCartaEspecial = true;
	else this->ehCartaEspecial = false;
}

int Cartas::get_numero(){
	return this->numero;
}

int Cartas::get_naipe(){
	return this->naipe;
}

bool Cartas::get_ehCartaEspecial(){
	return this->ehCartaEspecial;
}

void Cartas::imprimeCarta(){ 
	std::string valoresDasCartas = "A23456789 QJK";
	std::string naipes[4] = {" de ouros", " de espadas", " de copas", " de paus"}; 
	this->numero == 10 ? std::cout << 10 : std::cout << valoresDasCartas[this->numero-1];
	std::cout << naipes[this->naipe-1];
}

Cartas::~Cartas(){}