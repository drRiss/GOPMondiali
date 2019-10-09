

#ifndef CARTAINDIETRO_H_
#define CARTAINDIETRO_H_

#include "Carta.h"

using namespace std;

class CartaIndietro: public Carta {
public:
	CartaIndietro(string nome, int spostamento);
	virtual ~CartaIndietro();
	int getSpos() const;
	void setSpos(int spos);
	void effetto(GameController *partita, Giocatore *listaGiocatori[]);
	void messaggio ();

private:
	int spos;

};

#endif /* CARTAINDIETRO_H_ */
