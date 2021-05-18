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

int comparaForcaCartas(Cartas carta1, Cartas carta2){ //retorna 0 se a carta 1 for mais forte e 1 caso contrário
	if(carta1.get_ehCartaEspecial() && !carta2.get_ehCartaEspecial()) return 0; //a carta especial é sempre mais forte
	
	if(carta1.get_ehCartaEspecial() && carta2.get_ehCartaEspecial()) 
		if(carta1.get_naipe() > carta2.get_naipe()) return 0;  
	
	if(!carta1.get_ehCartaEspecial() && !carta2.get_ehCartaEspecial()){
		if(carta1.get_numero() <= 3 && carta2.get_numero() > 3) return 0;
		
		else if(carta1.get_numero() <= 3 && carta2.get_numero() <= 3){
			if(carta1.get_numero() > carta2.get_numero()) return 0;
		}else if(carta1.get_numero() > 3 && carta2.get_numero() > 3){
			if(carta1.get_numero() > carta2.get_numero()) return 0;
		}
	}
	
	return 1; //depois de testar todas as possibilidades da carta 1 ser mais forte, retorna 1
}

std::vector<Cartas> ordenaCartas(std::vector<Cartas> cartas){
	int quantidadeDeCartas = cartas.size();
	
	for(int i=0; i<quantidadeDeCartas; i++){ //percorre todas as cartas recebidas, ordenando-as por força
		for(int j=i; j<quantidadeDeCartas; j++){
			if(i != j && comparaForcaCartas(cartas[i], cartas[j])){
				Cartas aux = cartas[i];
				cartas[i] = cartas[j];
				cartas[j] = aux;
			}
		}
	}
	
	return cartas;
}
