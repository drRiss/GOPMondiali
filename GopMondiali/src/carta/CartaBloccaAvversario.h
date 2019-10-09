

#ifndef SRC_CARTA_CARTABLOCCAAVVERSARIO_H_
#define SRC_CARTA_CARTABLOCCAAVVERSARIO_H_

#include "Carta.h"

using namespace std;

class CartaBloccaAvversario: public Carta {
public:
	CartaBloccaAvversario(string nome);
	virtual ~CartaBloccaAvversario();
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio();
};

#endif /* SRC_CARTA_CARTABLOCCAAVVERSARIO_H_ */
