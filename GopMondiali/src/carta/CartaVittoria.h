

#ifndef CARTAVITTORIA_H_
#define CARTAVITTORIA_H_

#include "Carta.h"

using namespace std;

class CartaVittoria: public Carta {
public:
	CartaVittoria(string nome);
	virtual ~CartaVittoria();
	void effetto (GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio ();
};



#endif /* CARTAVITTORIA_H_ */
