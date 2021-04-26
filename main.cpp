#include <iostream>
#include <vector>
#include "Cartas.h"
#include "Baralho.h"

int main(){
	Baralho baralho;
	for(int j=0; j<100; j++){
		for(int i=0; i<4*4; i++){
			baralho.embaralhaCartas();
			baralho.imprimeCarta(i);
		}
		std::cout << "\n";
	}
	return 0;
}
