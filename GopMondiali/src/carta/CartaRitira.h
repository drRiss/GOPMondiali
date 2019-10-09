

#ifndef CARTARITIRA_H_
#define CARTARITIRA_H_

#include "Carta.h"

using namespace std;

class CartaRitira: public Carta {
public:
	CartaRitira(string nome);
	virtual ~CartaRitira();
	void effetto (GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio ();
};

#endif /* CARTARITIRA_H_ */
