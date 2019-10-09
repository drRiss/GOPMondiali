

#ifndef CASELLA_CASELLASALTATURNO_H_
#define CASELLA_CASELLASALTATURNO_H_

#include "Casella.h"
using namespace std;

class CasellaSaltaTurno: public Casella {
public:
	CasellaSaltaTurno();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio(Giocatore *giocatore);
};

#endif /* CASELLA_CASELLASALTATURNO_H_ */
