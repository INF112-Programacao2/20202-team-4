#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jogada.h"

Jogada::Jogada(){
	srand(time(NULL));
	
	baralho = Baralho();
	int entidadeAleatoria = 0;
	this->rodada = 1;
	this->turno = 0;
	this->turnoInicial = true;
	this->jogadorInicialRodada = entidadeAleatoria;
	this->jogadorInicialTurno = entidadeAleatoria;
	
	jogadores.push_back(new Troll("Pombal", 0)); //Nomes para homenagear as pessoas que inspiraram as personalidades 
	jogadores.push_back(new Calculista("Dilsao", 0));
	jogadores.push_back(new Corajoso("Vinicius", 0));
	jogadores.push_back(new Humano("Voce", 0));
}

Jogada::~Jogada(){}


int Jogada::get_rodada(){
	return this->rodada;
}

int Jogada::get_turno(){
	return this->turno;
}

void Jogada::distribuirCartas(){
	if(this->turnoInicial){
		int indiceJogador = 0;
		int indiceCarta = 0;
		
		baralho.embaralhaCartas();
		while(true){
			if(indiceCarta != 0 && indiceCarta%this->rodada == 0) indiceJogador++;
			if(indiceJogador == 4) break;
			this->jogadores[indiceJogador]->adicionaCarta(this->baralho.get_carta(indiceCarta));
			indiceCarta++;
		}
	}
}

void Jogada::determinaVencedorTurno(){
	this->cartasJogadas = ordenaCartas(this->cartasJogadas);
	for(int i=0; i<4; i++){
		for(int j=0; j<this->rodada; j++){
			if(this->jogadores[i]->get_carta(j).get_numero() == this->cartasJogadas[0].get_numero() && this->jogadores[i]->get_carta(j).get_naipe() == this->cartasJogadas[0].get_naipe()){
				this->jogadores[i]->set_pontos(1+this->jogadores[i]->get_pontos());
				std::cout << "\n\nO jogador " << this->jogadores[i]->get_nome() << " foi o vencedor do turno, jogando a carta ";
				this->cartasJogadas[0].imprimeCarta();
				std::cout << "\n";
				this->jogadorInicialTurno = i;
				return;
			}
		}
	}
}

void Jogada::jogaTurno(){
	if(this->turnoInicial){
		for(int i=this->jogadorInicialRodada; i<jogadorInicialRodada+4; i++){
			int apostaFeitaPorJogador = this->jogadores[i%4]->calculaJogada(this->turnoInicial, this->cartasJogadas);
          	std::cout << this->jogadores[i%4]->get_nome() << " aposta " << apostaFeitaPorJogador << " turnos\n";
			this->jogadores[i%4]->set_turnosApostados(apostaFeitaPorJogador);
		}
		this->turnoInicial = false;
	}else{
		int marcaCarta[4];
		for(int i=this->jogadorInicialTurno; i<jogadorInicialTurno+4; i++){
			marcaCarta[i%4] = this->jogadores[i%4]->calculaJogada(this->turnoInicial, this->cartasJogadas);
          	std::cout << this->jogadores[i%4]->get_nome() << " jogou ";
			jogadores[i%4]->get_carta(marcaCarta[i%4]).imprimeCarta();
			std::cout << std::endl;
			this->cartasJogadas.push_back(jogadores[i%4]->get_carta(marcaCarta[i%4]));
		}
		determinaVencedorTurno();
		for(int i=0; i<4; i++) jogadores[i]->removeCarta(marcaCarta[i]);
		this->cartasJogadas.clear();
	}
}

void Jogada::mudaTurno(){
	if(this->turno == this->rodada){
		this->turno = 0;
		this->rodada++; 
		this->turnoInicial = true;
	}else this->turno++;
}

void Jogada::mudaJogadorInicial(){
	if(this->turnoInicial) 
		this->jogadorInicialRodada = (this->jogadorInicialRodada+1)%4;
}
