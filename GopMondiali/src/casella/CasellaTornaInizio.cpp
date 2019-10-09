

#include "CasellaTornaInizio.h"
using namespace std;

CasellaTornaInizio::CasellaTornaInizio() {

	nome = "Casella Torna Inizio";

}

void CasellaTornaInizio::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->tornaInizio(listaGiocatori);
}

void CasellaTornaInizio::messaggio(Giocatore *giocatore){
	cout << "Oh no! Autogol clamoroso "<<  giocatore->getNome() <<  " torna all inizio!" << endl;
}


