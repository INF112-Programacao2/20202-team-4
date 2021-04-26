#include <iostream>
#include <vector>
#include "Cartas.h"

int main(){
	std::vector<Cartas*> carta;
	for(int i=1; i<=13; i++) for(int j=1; j<=4; j++) carta.push_back(new Cartas(i, j));
	for(int i=0; i<52; i++){carta[i]->imprimeCarta();std::cout << "\n\n";}
	return 0;
}