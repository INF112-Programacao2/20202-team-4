#include "Entidades.h"

Entidades::Entidades(std::string nome, int pontos)
{
    this->nome = nome;
    this->pontos = pontos;
}

std::string Entidades::get_nome()
{
    return this->nome;
}

int Entidades::get_pontos()
{
    return this->pontos;
}

void Entidades::adicionaCarta(Cartas cartaParaAdicionar)
{
	this->cartas.push_back(cartaParaAdicionar);
}
