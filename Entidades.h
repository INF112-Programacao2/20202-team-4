#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <string>
#include <vector>
#include "Cartas.h"

class Entidades{
protected:
	std::string nome; 
	int pontos;
	int turnosApostados;
	std::vector<Cartas> cartas;

public:
	Entidades(std::string nome, int pontos);
  	~Entidades();
	
	std::string get_nome();
	int get_pontos();
	int get_turnosApostados();
	int get_carta(int posicao);
  
	void set_pontos(int pontos);
	void set_turnosApostados(int apostas);
	
	void adicionaCarta(Cartas cartaParaAdicionar);
	virtual int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) = 0; 
	void ordenaCartasDaMao();
	void imprimeCarta(int posicao);
  	void removeCarta(int posicao);
};

#endif
