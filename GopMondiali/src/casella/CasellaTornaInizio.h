

#ifndef CASELLA_CASELLATORNAINIZIO_H_
#define CASELLA_CASELLATORNAINIZIO_H_


#include "Casella.h"
using namespace std;

class CasellaTornaInizio: public Casella {
public:
	CasellaTornaInizio();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio(Giocatore *giocatore)override;
};

#endif /* CASELLA_CASELLATORNAINIZIO_H_ */
