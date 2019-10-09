
#include "CartaRitira.h"
using namespace std ;

CartaRitira::CartaRitira(string nome) {
	setNome(nome);
}

CartaRitira::~CartaRitira() {
}
void CartaRitira::effetto(GameController *partita, Giocatore *listaGiocatori[]){

	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(risposta){
		partita->cambiaPosizione(listaGiocatori, partita->lanciaDado());
	}
}

void CartaRitira::messaggio(){
	cout << "Se indovinerai la prossima risposta potrai ritirare il dado!" << endl;
}


