
#include "CartaIndietro.h"
using namespace std;

CartaIndietro::CartaIndietro( string nome, int spostamento) {
	setNome(nome);
	setSpos(-spostamento);
}

CartaIndietro::~CartaIndietro() {
}

int CartaIndietro::getSpos() const {
	return spos;
}

void CartaIndietro::setSpos(int spos) {
	this->spos = spos;
}

void CartaIndietro::effetto(GameController *partita, Giocatore *listaGiocatori[]){

	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(!risposta){
		partita->cambiaPosizione(listaGiocatori, getSpos());
	}
}

void CartaIndietro::messaggio(){
	cout << "Se sbagli la prossima risposta tornerai indietri di " << -getSpos() << " caselle!" << endl;
}
