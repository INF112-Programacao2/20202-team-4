#ifndef FUNCOESUTEIS_H
#define FUNCOESUTEIS_H

#include "Cartas.h"

void imprimeMenuFixo(int rodadaAtual, int turnoAtual);
int comparaForcaCartas(Cartas carta1, Cartas carta2);
std::vector<Cartas> ordenaCartas(std::vector<Cartas> cartas);

#endif