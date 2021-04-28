#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "Jogada.h"
#include <string>

class Entidades:
{
protected:
    std::string nome; 
    int pontos;
    std::string cartas;

public:
    std::string get_nome();
    int get_pontos();

    Entidades(std::string nome, int pontos, std::string cartas);

    virtual int calculaJogada() = 0; 
};

#endif
