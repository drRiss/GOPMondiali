

#include "CasellaPescaCarta.h"
using namespace std;

CasellaPescaCarta::CasellaPescaCarta() {

	nome = "Casella Pesca Carta";
}

void CasellaPescaCarta::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->mazzoptr = partita->pescaCarta(partita->mazzoptr);
	partita->effettoCarta(partita->mazzoptr, listaGiocatori);
}


