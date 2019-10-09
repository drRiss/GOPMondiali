

#ifndef GAME_GAMECONTROLLER_H_
#define GAME_GAMECONTROLLER_H_

#include <iostream>
#include <ostream>
#include <string>
#include <cstring>

#include "../casella/Casella.h"
#include "../giocatore/Giocatore.h"
#include "../carta/Carta.h"
class Casella;
class Carta;


using namespace std;

class GameController {

	int numeroCaselle;
	Casella *tabellone[100];
	bool pFinita = false;
	int numeroGiocatori = 0;
	string nome;
	int attuale = 0;  //indice del giocatore attuale
	string esciOtab;
	typedef Carta* cartaptr;
	int delay = 1;

public:
	GameController();
	cartaptr domandeptr;
	cartaptr mazzoptr;
	void messaggioBenvenuto();
	void creaTabellone();
	int lanciaDado();
	void stampaTabellone();
//	void stampaGiocatore(Giocatore *giocatore);
	void cambiaPosizione(Giocatore *listaGiocatori[], int pos);
	void integritaTabellone();
	void setFinita(bool finita);
	void stampaPosizioni(Giocatore *listaGiocatori[]);
	void prossimoGiocatore();
	void saltaTurno(Giocatore *listaGiocatori[]);
	void tornaInizio(Giocatore *listaGiocatori[]);
	void flussoGioco(Giocatore *listaGiocatori[]);
	void bloccaAvversario(Giocatore *listaGiocatori[]);
	Giocatore** creaGiocatori();
	cartaptr creaMazzo();
	cartaptr mescolaMazzo(cartaptr head, int nc);
	cartaptr headLast(cartaptr head);
	cartaptr nodoEsimo(cartaptr head, int n);
	cartaptr ultimoptr(cartaptr head);
	cartaptr nodPrec(cartaptr head, cartaptr current);
	cartaptr pescaCarta (cartaptr head);
	void eseguiEffetto(Giocatore *listaGiocatori[]);
	void effettoCarta(cartaptr mazzoptr, Giocatore *listaGiocatori[]);
	void dimezzaPosizione(Giocatore *listaGiocatori[]);
	int getNumeroCaselle() const;
	void vinciPartita(Giocatore *listaGiocatori[]);
	cartaptr creaMazzoDomande();
	bool rispostaEsatta();
};

#endif /* GAME_GAMECONTROLLER_H_ */
