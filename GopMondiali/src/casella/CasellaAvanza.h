
#ifndef CASELLA_CASELLAAVANZA_H_
#define CASELLA_CASELLAAVANZA_H_

#include "Casella.h"

class CasellaAvanza: public Casella { // @suppress("Class has a virtual method and non-virtual destructor")
private:
	int move;

public:

	CasellaAvanza(int spostamento);
	void messaggio(Giocatore *giocatore);
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	int getMove() const;
	void setMove(int move);
};

#endif /* CASELLA_CASELLAAVANZA_H_ */
