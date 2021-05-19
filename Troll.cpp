#include <ctime>
#include <cstdlib>
#include "Troll.h"

Troll::Troll(std::string nome, int pontos):Entidades(nome, pontos){}


int Troll::calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas){
	srand(time(NULL));

	if(turnoInicial){
		return rand()%this->cartas.size(); //faz uma aposta aleatoria 
	}else return 0; //joga uma carta aleatoria da mão
}

Troll::~Troll(){}