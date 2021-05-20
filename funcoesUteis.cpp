#include <iostream>
#include <vector>
#include "funcoesUteis.h"

void imprimeMenuFixo(int rodadaAtual, int turnoAtual){
	std::cout << "A ordem das cartas e'\nCartas especiais: 4 de paus, 7 de copas, As de espadas, 7 de ouros\n";
	std::cout << "Cartas normais: 3, 2, A, K, J, Q, 7, 6, 5, 4\n"  << std::endl;
	std::cout << "Rodada: " << rodadaAtual << "\nTurno: ";
	if(turnoAtual == 0) std::cout << "Apostas";
	else std::cout << turnoAtual;
	std::cout << "\n\n";
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