

#include "CartaBloccaAvversario.h"

using namespace std;

CartaBloccaAvversario::CartaBloccaAvversario(string nome) {
	setNome(nome);
}

CartaBloccaAvversario::~CartaBloccaAvversario() {
}

void CartaBloccaAvversario::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
		risposta = partita->rispostaEsatta();
		if(risposta){
	partita->bloccaAvversario(listaGiocatori);
		}
}
void CartaBloccaAvversario::messaggio(){
	cout <<"Rispondi correttamente alla prossima domanda per bloccare il turno di un avversario a scelta!" << endl;
}



