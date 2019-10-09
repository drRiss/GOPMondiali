

#include "CasellaIndietro.h"
using namespace std;

CasellaIndietro::CasellaIndietro(int spostamento) {
	setMove(-spostamento);
	nome = "Casella Torna Indietro";
}

void CasellaIndietro :: effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->cambiaPosizione(listaGiocatori, getMove());

}

int CasellaIndietro::getMove() const {
	return move;
}

void CasellaIndietro::setMove(int move) {
	this->move = move;
}

void CasellaIndietro::  messaggio(Giocatore *giocatore){
	cout<< giocatore->getNome() << " torna indietro di " << -getMove()<<" caselle!" << endl;;

}

