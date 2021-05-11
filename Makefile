CC=g++
CFLAGS=-std=c++11	-Wall
all:	main

Potencia.o:	Potencia.h	Potencia.cpp
	${CC}	${CFLAGS}	-c	Potencia.cpp

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


main.o:	Cartas.h	Potencia.h  Entidades.h Calculista.h	Corajoso.h	Troll.h	Humano.h	Jogada.h	main.cpp
	${CC}	${CFLAGS}	-c	main.cpp

main:	main.o	Cartas.o	Potencia.o	Entidades.o	Calculista.o	Corajoso.o	Troll.o	Humano.o	Jogada.o
	${CC}	${CFLAGS}	-o	main	main.o	Cartas.o	Potencia.o	Entidades.o	Calculista.o	Corajoso.o	Troll.o	Humano.o	Jogada.o
#Rule for cleaning files generated during compilation.
#Call 'make clean' to use it
clean:
	rm	-f	main	*.o
