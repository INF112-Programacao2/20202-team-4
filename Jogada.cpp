#include <cstdlib>
#include <ctime>
#include "Jogada.h"

Jogada::Jogada(){
	baralho = Baralho();
	int entidadeAleatoria = rand()%4;
	this->rodada = 1;
	this->turno = 1;
	this->turnoInicial = true;
	this->jogadorInicialRodada = entidadeAleatoria;
	this->jogadorInicialTurno = entidadeAleatoria;
  	
  	jogadores.push_back(Troll("Pombal", 0));
  	jogadores.push_back(Calculista("Dilsao", 0));
    jogadores.push_back(Corajoso("Vinicius", 0));
	jogadores.push_back(Humano(0));
}

Jogada::~Jogada(){}


int get_rodada(){
	return this->rodada;
}

int get_turno(){
	return this->turno;
}

void Jogada::distribuirCartas(){
  	int indiceJogador = 0;
  	int indiceCarta = 0;
	
  	while(true){
    	if(indiceCarta != 0 && indiceCarta%this->rodada == 0) indiceJogador++;
      	if(indiceJogador == 4) break;
      	this->jogadores.adicionaCarta(this->baralho.get_carta(indiceCarta));
      	indiceCarta++;
    }
}

void Jogada::determinaVencedorTurno(){
  	this->cartasJogadas = ordenaCartas(this->cartasJogadas);
	for(int i=0; i<4; i++){
    	for(int j=0; j<this->rodada; j++){
        	if(this->jogadores[i].get_carta(j).get_numero() == this->cartasJogadas[0].get_numero() && this->jogadores[i].get_carta(j).get_naipe() == this->cartasJogadas[0].get_naipe()){
            	this->jogadores[i].set_pontos(this->jogadores[i].get_pontos()++);
              	std::cout << "O jogador " << this->jogadores[i].get_nome() << " foi o vencedor do turno, jogando a carta " << this->cartasJogadas[0].imprimeCarta() << "\n";
              	this->jogadorInicialTurno = i;
            }
        }
    }
}

void Jogada::jogaTurno(){
	if(this->turnoInicial){
    	for(int i=this->jogadorInicialRodada; i<i+4; i++){
          	int apostaFeitaPorJogador = this->jogadores[i%4].calculaJogada(this->turnoInicial, this->cartasJogadas);
          	this->jogadores[i%4].set_turnosApostados(apostaFeitaPorJogador); 
        }
      	this->turnoInicial = false;
    }else{
    	int marcaCarta[4];
      	for(int i=this->jogadorInicialTurno; i<i+4; i++){
  			marcaCarta[i%4] = this->jogadores[i%4].calculaJogada(this->turnoInicial, this->cartasJogadas);
          	this->cartasJogadas.push_back(jogadores[i%4].get_carta(marcaCarta[i%4]));
        }
		determinaVencedorTurno();
      	for(int i=0; i<4; i++) jogadores[i].removeCarta(marcaCarta[i]);
    }
}

void mudaTurno(){
    this->turno++;
	if(this->turno==this->rodada){
      	this->turnoturno = 0;
      	this->turnorodada++;
    	this->turnoInicial == true;
    }
}

void mudaJogadorInicial(){
	if(this->turnoInicial = true) 
    	this->jogadorInicialRodada = (this->jogadorInicialRodada+1)%4;
}