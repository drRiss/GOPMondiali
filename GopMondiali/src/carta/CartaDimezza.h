

#ifndef SRC_CARTA_CARTADIMEZZA_H_
#define SRC_CARTA_CARTADIMEZZA_H_

#include "Carta.h"

using namespace std;

class CartaDimezza: public Carta {
public:
	CartaDimezza(string nome);
	virtual ~CartaDimezza();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio ();
};



#endif /* SRC_CARTA_CARTADIMEZZA_H_ */
