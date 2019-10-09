
#ifndef CASELLA_CASELLAFINALE_H_
#define CASELLA_CASELLAFINALE_H_

#include "Casella.h"
#include "../game/GameController.h"

using namespace std;

class CasellaFinale: public Casella {
public:
	CasellaFinale();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio(Giocatore *giocatore)override;

};

#endif /* CASELLA_CASELLAFINALE_H_ */
