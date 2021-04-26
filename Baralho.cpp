#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Baralho.h"

Baralho::Baralho(){
	for(int i=1; i<=7; i++) for(int j=1; j<=4; j++) this->cartaBaralho.push_back(new Cartas(i,j));
	for(int i=11; i<=13; i++) for(int j=1; j<=4; j++) this->cartaBaralho.push_back(new Cartas(i,j));
}

void Baralho::embaralhaCartas(){
	srand(time(NULL));
	for(unsigned int i=0; i<500000; i++){
		int posicaoAleatoria = rand()%cartaBaralho.size();
		Cartas *aux = this->cartaBaralho[i%cartaBaralho.size()];
		this->cartaBaralho[i%cartaBaralho.size()] = this->cartaBaralho[posicaoAleatoria];
		this->cartaBaralho[posicaoAleatoria] = aux;
	}
}

void Baralho::imprimeCarta(int pos){
	this->cartaBaralho[pos]->imprimeCarta();
}

Baralho::~Baralho(){
	for(int i=0; i<cartaBaralho.size(); i++) delete this->cartaBaralho[i];
}