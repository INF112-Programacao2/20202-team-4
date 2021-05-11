#include <ctime>
#include <cstdlib>
#include "Corajoso.h"

Corajoso::Corajoso(std::string nome, int pontos):Entidades(nome, pontos){}

int Corajoso::calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
	std::vector<Cartas> cartasDaMaoOrdenadas = ordenaCartas(this->cartas);
	
	if(turnoInicial){
		srand(time(NULL));
		
		this->turnosApostados = 0;
		
		for(int i=0; i<cartasDaMaoOrdenadas.size(); i++){
			if(cartasDaMaoOrdenadas[i].get_ehCartaEspecial()){
				if(cartasDaMaoOrdenadas[i].get_numero() != 4){
					if(rand()%100 > 40) this->turnosApostados++;
				}else{
					this->turnosApostados++;
				}
			}
			
			else if(cartasDaMaoOrdenadas[i].get_numero() == 3 || cartasDaMaoOrdenadas[i].get_numero() == 2) this->turnosApostados++;
		}
		
		return this->turnosApostados;
	}else{
		cartasJogadas = ordenaCartas(cartasJogadas);
		int quantidadeCartas = cartasDaMaoOrdenadas.size();
		
		if(cartasJogadas.size() == 0) return quantidadeCartas >= 1 ? quantidadeCartas-1 : 0;
		
		if(this->turnosApostados == 0){
			for(int i=0; i<quantidadeCartas; i++)
				if(comparaForcaCartas(cartasDaMaoOrdenadas[i], cartasJogadas[0])) return i;
		}else{
			if(!comparaForcaCartas(cartasDaMaoOrdenadas[0], cartasJogadas[0])) return 0;
		}
		
		return quantidadeCartas >= 1 ? quantidadeCartas-1 : 0;
	}
}