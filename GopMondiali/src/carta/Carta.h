

#ifndef CARTA_H_
#define CARTA_H_
#include <string>
#include <cstring>
#include "../game/GameController.h"
class GameController;
using namespace std;



class Carta {

protected:
	string nome;
	int rispEsatta;
	string domanda;
public:
	Carta();
	virtual ~Carta();
	const string& getNome() const;
	void setNome(const string& nome);
	virtual void effetto(GameController *partita, Giocatore *listaGiocatori[]){};
	virtual void messaggio() {
	}
	const string& getDomanda() const;
	void setDomanda(const string& domanda);
	int getRispEsatta() const;
	void setRispEsatta(int rispEsatta);
	Carta* next;
	string risposta[4];
};


#endif /* CARTA_H_ */
