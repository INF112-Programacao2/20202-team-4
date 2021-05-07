#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Corajoso.h"

Corajoso::Corajoso(std::string nome, int pontos):Entidades(nome, pontos){}

int Corajoso::calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
	std::vector<Cartas> cartasDaMaoOrdenadas = ordenaCartas(this->cartas);
	
	if(turnoInicial){
		srand(time(NULL));
		
		int quantidadeTurnosApostados = 0;
		
		for(int i=0; i<cartasDaMaoOrdenadas.size(); i++){
			if(cartasDaMaoOrdenadas[i].get_ehCartaEspecial() && cartasDaMaoOrdenadas[i].get_numero() != 4){
				if(rand()%100 > 40) quantidadeTurnosApostados++;
			}
			
			else if(cartasDaMaoOrdenadas[i].get_numero() == 3 || cartasDaMaoOrdenadas[i].get_numero() == 2) quantidadeTurnosApostados++;
		}
		
		return quantidadeTurnosApostados;
	}
}