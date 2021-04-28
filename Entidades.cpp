#include "Entidades.h"

Entidades::Entidades(std::string nome, int pontos, std::string cartas)
{
    this->nome = nome;
    this->pontos = pontos;
    this->cartas = cartas;
}

std::string Entidades::get_nome()
{
    return this->nome;
}

int Entidades::get_pontos()
{
    return this->pontos;
}
