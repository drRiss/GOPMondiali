
#ifndef GAME_CASELLA_H_
#define GAME_CASELLA_H_
#include <string>
#include <cstring>

#include "../game/GameController.h"
#include "../giocatore/Giocatore.h"

class GameController;
using namespace std;


class Casella {

protected:


public:
	Casella();
	virtual ~ Casella();
	virtual void effetto(GameController *partita, Giocatore *listaGiocatori[]){};
	virtual void messaggio(Giocatore *giocatore){};
	string nome;
};

#endif /* GAME_CASELLA_H_ */
