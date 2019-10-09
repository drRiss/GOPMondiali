
#include "CasellaSaltaTurno.h"
using namespace std;

CasellaSaltaTurno::CasellaSaltaTurno() {

	nome = "Casella Salta Turno";
}

void CasellaSaltaTurno::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->saltaTurno(listaGiocatori);
}
void CasellaSaltaTurno::messaggio (Giocatore *giocatore){
	cout<< giocatore->getNome()<< " salterà il prossimo turno!"<< endl;
}


