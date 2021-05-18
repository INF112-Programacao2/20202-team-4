#include "Entidades.h"

Entidades::Entidades(std::string nome, int pontos)
{
	this->nome = nome;
	this->pontos = pontos;
	this->turnosApostados = 0;
}

Entidades::~Entidades(){}

std::string Entidades::get_nome()
{
	return this->nome;
}

int Entidades::get_pontos()
{
	return this->pontos;
}

int Entidades::get_turnosApostados()
{
	return this->turnosApostados;
}

Cartas Entidades::get_carta(int posicao)
{
	return this->cartas[posicao];
}

void Entidades::set_pontos(int pontos)
{
	this->pontos = pontos;
}

void Entidades::set_turnosApostados(int apostas)
{
	this->turnosApostados = apostas;
}

void Entidades::adicionaCarta(Cartas cartaParaAdicionar) //Adiciona carta na mão do jogador
{
	this->cartas.push_back(cartaParaAdicionar);
}

void Entidades::ordenaCartasDaMao()
{
	this->cartas = ordenaCartas(this->cartas);
}

void Entidades::imprimeCarta(int posicao)
{
	this->cartas[posicao].imprimeCarta();
}

void Entidades::removeCarta(int posicao)
{
	this->cartas.erase(cartas.begin()+posicao);
}
