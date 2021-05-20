CC=g++
CFLAGS=-std=c++11	-Wall
all:	main

Baralho.o:	Baralho.h	Baralho.cpp
	${CC}	${CFLAGS}	-c	Baralho.cpp

Cartas.o:	Cartas.h	Cartas.cpp
	${CC}	${CFLAGS}	-c	Cartas.cpp

Entidades.o:	Entidades.h	Entidades.cpp
	${CC}	${CFLAGS}	-c	Entidades.cpp

Calculista.o:	Calculista.h	Calculista.cpp
	${CC}	${CFLAGS}	-c	Calculista.cpp

Corajoso.o:	Corajoso.h	Corajoso.cpp
	${CC}	${CFLAGS}	-c	Corajoso.cpp

Troll.o:	Troll.h	Troll.cpp
	${CC}	${CFLAGS}	-c	Troll.cpp

Humano.o:	Humano.h	Humano.cpp
	${CC}	${CFLAGS}	-c	Humano.cpp

Jogada.o:	Jogada.h	Jogada.cpp
	${CC}	${CFLAGS}	-c	Jogada.cpp

FuncoesUteis.o: FuncoesUteis.h FuncoesUteis.cpp
	${CC}	${CFLAGS}	-c	FuncoesUteis.cpp

main.o:	Baralho.h Cartas.h	Entidades.h Calculista.h	Corajoso.h	Troll.h	Humano.h	Jogada.h	FuncoesUteis.h main.cpp
	${CC}	${CFLAGS}	-c	main.cpp

main:	main.o	Baralho.o Cartas.o Entidades.o	Calculista.o	Corajoso.o	Troll.o	Humano.o	Jogada.o FuncoesUteis.o
	${CC}	${CFLAGS}	-o	main	main.o	Baralho.o Cartas.o	Entidades.o	Calculista.o	Corajoso.o	Troll.o	Humano.o	Jogada.o FuncoesUteis.o
#Rule for cleaning files generated during compilation.
#Call 'make clean' to use it
clean:
	rm	-f	main	*.o
