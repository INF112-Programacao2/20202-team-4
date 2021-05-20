#include <iostream>
#include "Humano.h"

Humano::Humano(std::string nome, int pontos):Entidades(nome, pontos){}

void trataExcecoes(int cartaOuApostaEscolhida, bool turnoInicial, int quantidadeMaxima){
	if(turnoInicial && cartaOuApostaEscolhida < 0) throw "Voce aposta menos que zero turnos, tem certeza?\n";
	else if(turnoInicial && cartaOuApostaEscolhida > quantidadeMaxima) throw "Voce nao pode apostar tudo isso, leia o readme\n";
	else if(!turnoInicial && cartaOuApostaEscolhida < 0) throw "Como voce pode ter menos que zero cartas? Pensa um pouco\n";
	else if(!turnoInicial && cartaOuApostaEscolhida > quantidadeMaxima) throw "Por acaso voce tem tanta carta assim?\n";
	else if(!turnoInicial && cartaOuApostaEscolhida == 0) throw "Nao existe indice 0 para carta\n";
}

int capturaResposta(){
	int jogadaEscolhida;
	std::cin >> jogadaEscolhida;
	return jogadaEscolhida;
}

int Humano::calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
	std::vector<Cartas> cartasDaMaoOrdenadas = ordenaCartas(this->cartas);
	
	std::cout << "\n\nSuas cartas sao: ";
	for (int i = 0; i < this->cartas.size(); i++){
		std::cout << i+1 << ": ";
		this->cartas[i].imprimeCarta(); 
		std::cout << (i == this->cartas.size()-1 ? "\n" : ", "); //imprimir virgula e a proxima carta ate o final, imprimindo um \n
	}
	
	if(turnoInicial){ //Se for o inicio da rodada, as apostas serão feitas
		std::cout << "Sua aposta: ";
		while(true){
			int cartaOuApostaEscolhida = capturaResposta();
			try{
				trataExcecoes(cartaOuApostaEscolhida, turnoInicial, this->cartas.size());
				this->turnosApostados = cartaOuApostaEscolhida;
				break;
			}catch(const char* e){
				std::cerr << e;
			}
		} //tratamento de exceção para que o usuario nao escolha uma aposta fora do escopo
		std::cout << "\n\n";
		return this->turnosApostados;
	}else{
		int posicaoEscolhida;
		std::cout << "Escolha uma carta (pela posicao): ";
		while(true){
			int cartaOuApostaEscolhida = capturaResposta();
			try{
				trataExcecoes(cartaOuApostaEscolhida, turnoInicial, this->cartas.size());
				posicaoEscolhida = cartaOuApostaEscolhida;
				break;
			}catch(const char* e){
				std::cerr << e;
			}
		} //tratamento de exceção para que o usuario nao escolha uma carta fora do escopo
		std::cout << "\n\n";
		return posicaoEscolhida-1;
    }
}

Humano::~Humano(){}