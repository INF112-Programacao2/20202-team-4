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

int Entidades::get_carta(int posicao)
{
	return this->cartas[posicao];
}

void Entidades::set_pontos(int pontos)
{
	this->pontos = pontos;
}
