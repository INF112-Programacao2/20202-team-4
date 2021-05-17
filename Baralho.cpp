#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Baralho.h"

Baralho::Baralho(){
	for(int i=1; i<=7; i++) for(int j=1; j<=4; j++) this->cartaBaralho.push_back(Cartas(i, j));
	for(int i=11; i<=13; i++) for(int j=1; j<=4; j++) this->cartaBaralho.push_back(Cartas(i, j));
}

Baralho::~Baralho(){}

Cartas Baralho::get_carta(int posicao){
	return this->cartaBaralho(posicao);
}

void Baralho::embaralhaCartas(){
	srand(time(NULL));
	for(unsigned int i=0; i<500000; i++){
		int posicaoAleatoria = rand()%this->cartaBaralho.size();
		Cartas aux = this->cartaBaralho[i%this->cartaBaralho.size()];
		this->cartaBaralho[i%this->cartaBaralho.size()] = this->cartaBaralho[posicaoAleatoria];
		this->cartaBaralho[posicaoAleatoria] = aux;
	}
}

void Baralho::imprimeCarta(int pos){
	this->cartaBaralho[pos].imprimeCarta();
}
