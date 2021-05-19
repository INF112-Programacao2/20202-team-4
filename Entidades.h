#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <string>
#include <vector>
#include "Cartas.h"

class Entidades{
protected:
	std::string nome;
	int turnosVencidos;
	int turnosApostados;
	int vida;
	std::vector<Cartas> cartas;

public:
	Entidades(std::string nome, int turnosVencidos);
  	~Entidades();
	
	std::string get_nome();
	int get_turnosVencidos();
	int get_turnosApostados();
	int get_vida();
	Cartas get_carta(int posicao);
  
	void set_turnosVencidos(int turnosVencidos);
	void set_turnosApostados(int apostas);
	void set_vida(int vida);
	
	void adicionaCarta(Cartas cartaParaAdicionar);
	virtual int calculaJogada(bool turnoInicial, std::vector<Cartas> cartasJogadas) = 0; 
	void ordenaCartasDaMao();
	void imprimeCarta(int posicao);
  	void removeCarta(int posicao);
};

#endif
