

#include "CartaVittoria.h"
using namespace std;

CartaVittoria::CartaVittoria(string nome) {
	setNome(nome);
}
CartaVittoria::~CartaVittoria() {
}
void CartaVittoria::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	bool risposta;
	partita->domandeptr=partita->pescaCarta(partita->domandeptr);
	risposta = partita->rispostaEsatta();
	if(risposta){
		partita->vinciPartita(listaGiocatori);
	}
}
void CartaVittoria::messaggio (){
	cout << "Attenzione...." << endl;
	cout << "Colpo di scena!" << endl;
	cout << "L'arbitro fischia un calcio di rigore al 90esimo" << endl;
	cout << "Indovina la prossima risposta per poter vincere la partita!"<< endl;
}


