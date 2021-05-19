#include <ctime>
#include <cstdlib>
#include "Corajoso.h"

Corajoso::Corajoso(std::string nome, int pontos):Entidades(nome, pontos){}

int Corajoso::calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
	std::vector<Cartas> cartasDaMaoOrdenadas = ordenaCartas(this->cartas);
	
	if(turnoInicial){ //Se for o inicio da rodada, as apostas serão feitas
		srand(time(NULL));
		
		this->turnosApostados = 0;
		
		for(int i=0; i<cartasDaMaoOrdenadas.size(); i++){ //Percorre as cartas da mão e testa se são especiais ou não
			if(cartasDaMaoOrdenadas[i].get_ehCartaEspecial()){ //Testa se a carta especial é um 4 de paus (a carta mais forte do jogo)
				if(cartasDaMaoOrdenadas[i].get_numero() != 4){  
					if(rand()%100 > 40) this->turnosApostados++; //Caso não seja, há 60% de chance do bot "escolher" uma jogada arriscada
				}else{
					this->turnosApostados++; //100% de chance de apostar que faz se tiver o 4 de paus (aposta certeira)
				}
			}
			
			else if(cartasDaMaoOrdenadas[i].get_numero() == 3 || cartasDaMaoOrdenadas[i].get_numero() == 2) 
				this->turnosApostados++; //100% de chance de apostar que faz uma carta mediana (outra jogada arriscada)
		}
		
		return this->turnosApostados;
	}else{ //Durante a rodada, aqui a jogada é calculada baseada na aposta feita no inicio
		cartasJogadas = ordenaCartas(cartasJogadas); //ordena as cartas jogadas anteriormente na rodada baseado em força (a jogada é calculada através da posição)
		int quantidadeCartas = cartasDaMaoOrdenadas.size(); 
		
		if(cartasJogadas.size() == 0) return quantidadeCartas >= 1 ? quantidadeCartas-1 : 0; //Testa se só sobrou uma carta e escolhe ela
		
		if(this->turnosApostados == 0){ //Caso a aposta seja de ganhar 0 turnos,
			for(int i=0; i<quantidadeCartas; i++)
				if(comparaForcaCartas(cartasDaMaoOrdenadas[i], cartasJogadas[0])) return i; //joga a carta mais forte da mão que seja mais fraca que a mais forte da mesa
		}else{
			if(!comparaForcaCartas(cartasDaMaoOrdenadas[0], cartasJogadas[0])) return 0; //Descarta a carta mais forte se for possível
		}
		
		return quantidadeCartas >= 1 ? quantidadeCartas-1 : 0; //Depois de jogar uma carta, remove ela do baralho
	}
}

Corajoso::~Corajoso(){}