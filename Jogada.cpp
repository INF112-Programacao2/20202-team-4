#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jogada.h"

Jogada::Jogada(std::string nomeUsuario){
	srand(time(NULL));
	
	baralho = Baralho();
	int entidadeAleatoria = rand()%4; //Seleciona jogador aleatório para iniciar o jogo
	this->rodada = 1;
	this->turno = 0;
	this->turnoInicial = true;
	this->jogadorInicialRodada = entidadeAleatoria;
	this->jogadorInicialTurno = entidadeAleatoria;
	
	this->jogadores.push_back(new Troll("Pombal", 0)); //Nomes para homenagear as pessoas que inspiraram as personalidades 
	this->jogadores.push_back(new Calculista("Dilsao", 0));
	this->jogadores.push_back(new Corajoso("Vinicius", 0));
	//this->jogadores.push_back(new Humano(nomeUsuario, 0)); //Jogadores adicionados à partida
}

Jogada::~Jogada(){
	this->jogadores.clear();
}


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
			if(indiceCarta != 0 && indiceCarta%this->rodada == 0) indiceJogador++; //Muda o jogador que recebe as cartas quando o outro recebeu (rodada) cartas
			if(indiceJogador == this->jogadores.size()) break; //Para a distribuição quando o último jogador recebe suas devidas cartas
			this->jogadores[indiceJogador]->adicionaCarta(this->baralho.get_carta(indiceCarta));
			indiceCarta++;
		}
	}
}

//A função compara a carta vencedora do turno com as cartas dos jogadores. Quem a tiver jogado, venceu
void Jogada::determinaVencedorTurno(){
	this->cartasJogadas = ordenaCartas(this->cartasJogadas);
	for(int i=0; i<this->jogadores.size(); i++){
		for(int j=0; j<this->rodada; j++){
			if(this->jogadores[i]->get_carta(j).get_numero() == this->cartasJogadas[0].get_numero() && this->jogadores[i]->get_carta(j).get_naipe() == this->cartasJogadas[0].get_naipe()){
				this->jogadores[i]->set_turnosVencidos(1+this->jogadores[i]->get_turnosVencidos());
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
	std::cout << "Ordem dos jogadores: ";
	
	if(this->turnoInicial){ //Turno de apostas
	
		for(int i=this->jogadorInicialRodada; i<jogadorInicialRodada+this->jogadores.size(); i++){
			std::cout << this->jogadores[i%this->jogadores.size()]->get_nome() << (i+1 == jogadorInicialRodada+this->jogadores.size() ? "\n\n" : ", "); //Imprime a ordem inicial dos jogadores
		}
		
		for(int i=this->jogadorInicialRodada; i<jogadorInicialRodada+this->jogadores.size(); i++){
			int apostaFeitaPorJogador = this->jogadores[i%this->jogadores.size()]->calculaJogada(this->turnoInicial, this->cartasJogadas);
          	std::cout << this->jogadores[i%this->jogadores.size()]->get_nome() << " aposta " << apostaFeitaPorJogador << " turnos\n";
			this->jogadores[i%this->jogadores.size()]->set_turnosApostados(apostaFeitaPorJogador);
		}
		this->turnoInicial = false;
	}else{
		
		for(int i=this->jogadorInicialTurno; i<jogadorInicialTurno+this->jogadores.size(); i++){
			std::cout << this->jogadores[i%this->jogadores.size()]->get_nome() << (i+1 == jogadorInicialTurno+this->jogadores.size() ? "\n\n" : ", "); //Imprime a ordem dos jogadores
		}
		
		int marcaCarta[this->jogadores.size()]; //Marca carta jogada para remover de cada entidade depois que for declarado o vencedor
		for(int i=this->jogadorInicialTurno; i<jogadorInicialTurno+this->jogadores.size(); i++){
			marcaCarta[i%this->jogadores.size()] = this->jogadores[i%this->jogadores.size()]->calculaJogada(this->turnoInicial, this->cartasJogadas);
          	std::cout << this->jogadores[i%this->jogadores.size()]->get_nome() << " jogou ";
			this->jogadores[i%this->jogadores.size()]->get_carta(marcaCarta[i%this->jogadores.size()]).imprimeCarta();
			std::cout << std::endl;
			this->cartasJogadas.push_back(this->jogadores[i%this->jogadores.size()]->get_carta(marcaCarta[i%this->jogadores.size()]));
		}
		determinaVencedorTurno();
		for(int i=0; i<this->jogadores.size(); i++) this->jogadores[i]->removeCarta(marcaCarta[i]);
		this->cartasJogadas.clear(); //Limpa mesa após turno
	}
}

void Jogada::analiseRodada(){
	for(int i=0; i<this->jogadores.size(); i++){
		if(this->jogadores[i]->get_turnosVencidos() != this->jogadores[i]->get_turnosApostados()){
			this->jogadores[i]->set_vida(this->jogadores[i]->get_vida()-1);
			if(this->jogadores[i]->get_vida() == 0) this->jogadores.erase(this->jogadores.begin()+i); //Remove jogador com 0 vidas
		}
		
		this->jogadores[i]->set_turnosVencidos(0);
	}
	
	if(this->jogadores.size() == 1) std::cout << "PARABENS " << this->jogadores[0]->get_nome() << " VOCE VENCEU!!!";
}

void Jogada::mudaTurno(){
	if(this->turno == this->rodada){
		this->turno = 0;
		this->rodada++;
		this->turnoInicial = true;
		analiseRodada();
	}else this->turno++;
}

void Jogada::mudaJogadorInicial(){
	if(this->turnoInicial) 
		this->jogadorInicialRodada = (this->jogadorInicialRodada+1)%this->jogadores.size(); //Rodada nova sempre começa com jogador aleatório
}

void Jogada::imprimeVidas(){
	std::cout << "Vidas: ";
	for(int i=0; i<this->jogadores.size(); i++){
		std::cout << this->jogadores[i]->get_nome() << " - " << this->jogadores[i]->get_vida() << (i+1 == this->jogadores.size() ? "\n" : ", ");
	}
}