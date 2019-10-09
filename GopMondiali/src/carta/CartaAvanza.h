

#ifndef CARTAAVANZA_H_
#define CARTAAVANZA_H_

#include "Carta.h"

namespace std {

class CartaAvanza: public Carta {
public:
	CartaAvanza(string nome, int spostamento);
	virtual ~CartaAvanza();
	int getSpostamento() const;
	void setSpostamento(int spostamento);
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio();
private:
	int spostamento;
};

} /* namespace std */

#endif /* CARTAAVANZA_H_ */
