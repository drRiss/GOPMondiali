

#include "CasellaFinale.h"
using namespace std;

CasellaFinale::CasellaFinale() {

	nome =  "Finish";
}

void CasellaFinale::effetto(GameController *partita, Giocatore *listaGiocatori[]){
	partita->setFinita(true);

}
void CasellaFinale::messaggio(Giocatore *giocatore){
	cout << "Congratulazioni, " << giocatore->getNome() << " vince la partita!" << endl;

}


