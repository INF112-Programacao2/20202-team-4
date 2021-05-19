#include "Entidades.h"

Entidades::Entidades(std::string nome, int turnosVencidos)
{
	this->nome = nome;
	this->turnosVencidos = turnosVencidos;
	this->turnosApostados = 0;
	this->vida = 3;
}

Entidades::~Entidades(){}

std::string Entidades::get_nome()
{
	return this->nome;
}

int Entidades::get_turnosVencidos()
{
	return this->turnosVencidos;
}

int Entidades::get_turnosApostados()
{
	return this->turnosApostados;
}

int Entidades::get_vida()
{
	return this->vida;
}

Cartas Entidades::get_carta(int posicao)
{
	return this->cartas[posicao];
}

void Entidades::set_turnosVencidos(int turnosVencidos)
{
	this->turnosVencidos = turnosVencidos;
}

void Entidades::set_turnosApostados(int apostas)
{
	this->turnosApostados = apostas;
}

void Entidades::set_vida(int vida)
{
	this->vida = vida;
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
