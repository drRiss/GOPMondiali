

#include "CasellaAvanza.h"
using namespace std;


CasellaAvanza::CasellaAvanza(int spostamento) {
	setMove(spostamento);
	nome = "Casella Avanza";
}

void CasellaAvanza :: effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->cambiaPosizione(listaGiocatori, getMove());
	//partita->eseguiEffetto(listaGiocatori);

}

void CasellaAvanza::setMove(int move) {
	this->move = move;
}

int CasellaAvanza::getMove() const {
	return move;
}

void CasellaAvanza:: messaggio(Giocatore *giocatore){
	 cout <<  giocatore->getNome() << " avanza di: " << getMove() << " caselle!" << endl;

}




