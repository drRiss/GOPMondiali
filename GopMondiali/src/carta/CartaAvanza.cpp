

#include "CartaAvanza.h"
#include "../game/GameController.h"
using namespace std;

CartaAvanza::CartaAvanza(string nome, int spostamento) {
	 setSpostamento(spostamento);
	 setNome(nome);
}

CartaAvanza::~CartaAvanza() {
}


void CartaAvanza:: effetto(GameController *partita, Giocatore *listaGiocatori[]){
	/*
	 * partita->domandaptr = partita->pesca domanda()
	 * partita->getRisposta(headdomanda) =
	 *
	 */
	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(risposta){

	partita->cambiaPosizione(listaGiocatori,getSpostamento());
	}
	//partita->eseguiEffetto(listaGiocatori);
}

void CartaAvanza::messaggio(){
	cout << "Rispondi correttamente alla prossima domanda per avanzare di "<<  getSpostamento() << " caselle!" << endl;

}

int CartaAvanza::getSpostamento() const {
	return spostamento;
}

void CartaAvanza::setSpostamento(int spostamento) {
	this->spostamento = spostamento;
}
