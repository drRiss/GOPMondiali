

#include "CartaDimezza.h"
using namespace std;

CartaDimezza::CartaDimezza(string nome) {
	setNome(nome);

}

CartaDimezza::~CartaDimezza() {
}

void CartaDimezza::effetto(GameController *partita, Giocatore *listaGiocatori[]){

	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(!risposta){
		partita->dimezzaPosizione(listaGiocatori);
	}
}
void CartaDimezza::messaggio(){
	cout << "Se sbagli la prossima risposta, la tua posizione verrà dimezzata! "  << endl;

}
