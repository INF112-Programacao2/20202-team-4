#include <iostream>
#include <cstdlib>
#include "Jogada.h"
#include "funcoesUteis.h"

int main(){
	system("cls || clear");
	std::string nomeUsuario;
	
	std::cout << "Bem vindo ao Acertadinha! Digite seu nome para iniciar uma partida" << std::endl;
	std::cin >> nomeUsuario;
	
	Jogada jogada(nomeUsuario);
	while(jogada.get_rodaJogo()){
		system("cls || clear"); //"cls" para windows e "clear" para linux
		imprimeMenuFixo(jogada.get_rodada(), jogada.get_turno());
		jogada.imprimeVidas();
		jogada.distribuirCartas();
		jogada.jogaTurno();
		jogada.mudaTurno();
		jogada.mudaJogadorInicial();
		std::cout << "\n\n\n";
		system("pause");
    }
	
	return 0;
}
