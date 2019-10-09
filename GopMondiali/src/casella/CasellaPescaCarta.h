

#ifndef CASELLA_CASELLAPESCACARTA_H_
#define CASELLA_CASELLAPESCACARTA_H_

#include "Casella.h"
using namespace std;

class CasellaPescaCarta: public Casella {
public:
	CasellaPescaCarta();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);

};

#endif /* CASELLA_CASELLAPESCACARTA_H_ */
