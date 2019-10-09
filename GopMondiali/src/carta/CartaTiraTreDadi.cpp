

#include "CartaTiraTreDadi.h"
using namespace std;

CartaTiraTreDadi::CartaTiraTreDadi(string nome) {
	setNome(nome);
}

CartaTiraTreDadi::~CartaTiraTreDadi() {
}

void CartaTiraTreDadi::effetto(GameController *partita, Giocatore *listaGiocatori[]){

	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(risposta){
		int dado = 0;

		for (int i = 0; i < 3; ++i) {
			dado = dado + partita->lanciaDado();
		}
		partita->cambiaPosizione(listaGiocatori, dado);
	}
}

void CartaTiraTreDadi::messaggio(){
	cout << "Se indovinerai la prossima risposta potrai tirare il dado tre volte!" << endl;
}

