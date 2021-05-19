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
	while(jogada.get_rodada() <= 4){
		system("cls || clear"); //"cls" para windows e "clear" para linux
		imprimeMenuFixo();
		std::cout << "Rodada: " << jogada.get_rodada() << "\nTurno: " << jogada.get_turno() << "\n\n";
		jogada.imprimeVidas();
		jogada.distribuirCartas();
		jogada.jogaTurno();
		jogada.mudaTurno();
		jogada.mudaJogadorInicial();
		std::cout << "\n\n\n";
		system("pause");
    }
	
	system("cls || clear");
	std::cout << "Acabou, todos nos somos vencedores apenas por participar" << std::endl;

	return 0;
}
