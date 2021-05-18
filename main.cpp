#include <iostream>
#include <cstdlib>
#include "Jogada.h"

int main(){
	system("cls || clear");
	std::string nomeUsuario;

	std::cout << "Bem vindo ao Acertadinha! Digite seu nome para iniciar uma partida" << std::endl;
	std::cin >> nomeUsuario;
	
	Jogada jogada;
	while(jogada.get_rodada() <= 4){
		system("cls || clear"); //"cls" para windows e "clear" para linux
		std::cout << "A ordem das cartas e'\nCartas especiais: 4 de paus, 7 de copas, As de espadas, 7 de ouros\n";
		std::cout << "Cartas normais: 3, 2, A, K, J, Q, 7, 6, 5, 4\n"  << std::endl;
		std::cout << "Rodada: " << jogada.get_rodada() << "\nTurno: " << jogada.get_turno() << "\n\n";
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
