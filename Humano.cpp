#include <iostream>
#include "Humano.h"

Humano::Humano(std::string nome, int pontos):Entidades(nome, pontos){}

int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
  	std::vector<Cartas> cartasDaMaoOrdenadas = ordenaCartas(this->cartas);
  
	if(turnoInicial){ //Se for o inicio da rodada, as apostas serão feitas
		std::cout << "Sua aposta: ";
		do{
			cin >> this->turnosApostados;
        }while(this->turnosApostados < 0 || this->turnosApostados >= this->cartas.size()); //tratamento de exceção para que o usuario nao escolha uma aposta fora do escopo 
      
      return this->turnosApostados;
    }else{
		std::cout << "\n\nSuas cartas sao: "
      	for (int i = 0; i < this->cartas.size(); i++){
            std::cout << i+1 << ": ";
          	cartas[i].imprimeCarta(); 
          	std::cout << (i == this->cartas.size()-1 ? "\n" : ", "); //imprimir virgula e a proxima carta ate o final, imprimindo um \n
        }
      
      	int posicaoEscolhida;
      	std::cout << "\n\nEscolha uma carta (pela posicao): ";
      	do{
          std::cin >> posicaoEscolhida;
        }while(posicaoEscolhida < 0 || posicaoEscolhida >= this->cartas.size()); //tratamento de exceção para que o usuario nao escolha uma carta fora do escopo 
    }
}
