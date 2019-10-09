

#ifndef CASELLA_CASELLAINDIETRO_H_
#define CASELLA_CASELLAINDIETRO_H_

#include "Casella.h"
using namespace std;

class CasellaIndietro: public Casella {
private:
	int move;
public:
	CasellaIndietro(int spostamento);
	void effetto(GameController * partita, Giocatore *listaGiocatori[])override;
	int getMove() const;
	void setMove(int move);
	void messaggio(Giocatore *giocatore);
};

#endif /* CASELLA_CASELLAINDIETRO_H_ */
