

#ifndef SRC_CARTA_CARTATIRATREDADI_H_
#define SRC_CARTA_CARTATIRATREDADI_H_

#include "Carta.h"

using namespace std;

class CartaTiraTreDadi: public Carta {
public:
	CartaTiraTreDadi(string nome);
	virtual ~CartaTiraTreDadi();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio ();
};



#endif /* SRC_CARTA_CARTATIRATREDADI_H_ */
