#include <iostream>
#include <cstdlib>
#include "Jogada.h"

int main(){
	std::string nomeUsuario;

	std::cout << "Bem vindo ao Acertadinha! Digite seu nome para iniciar uma partida" << std::endl;
	std::cin >> nomeUsuario;
	
	Jogada jogada;
	while(jogada.get_rodada() <= 9){
		system("cls || clear"); //"cls" para windows e "clear" para linux
		std::cout << "A ordem das cartas e'\nCartas especiais: 4 de paus, 7 de copas, As de espadas, 7 de ouros\nCartas normais: 3, 2, A, K, J, Q, 7, 6, 5, 4"  << std::endl;
		jogada.distribuirCartas();
		jogada.jogaTurno();
		jogada.mudaTurno();
		jogada.mudaJogadorInicial();
    }
	
	std::cout << "Acabou, todos nos somos vencedores apenas por participar ¯\_(ツ)_/¯" << std::endl;

	return 0;
}
