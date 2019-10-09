

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <time.h>
#include <unistd.h>

using namespace std;

#include "../game/GameController.h"
#include "../casella/Casella.h"
#include "../casella/CasellaVuota.h"
#include "../casella/CasellaAvanza.h"
#include "../casella/CasellaIndietro.h"
#include "../casella/CasellaPescaCarta.h"
#include "../casella/CasellaSaltaTurno.h"
#include "../casella/CasellaTornaInizio.h"
#include "../casella/CasellaFinale.h"
#include "../casella/CasellaIniziale.h"
#include "../giocatore/Giocatore.h"
#include "../carta/Carta.h"
#include "../carta/CartaTiraTreDadi.h"
#include "../carta/CartaBloccaAvversario.h"
#include "../carta/CartaVittoria.h"
#include "../carta/CartaRitira.h"
#include "../carta/CartaIndietro.h"
#include "../carta/CartaAvanza.h"
#include "../carta/CartaDimezza.h"
#include "../carta/CartaDomanda.h"

typedef Carta* cartaptr;

GameController::GameController() {

	messaggioBenvenuto();
	sleep(2);

	srand((unsigned int)time(0));

	// inserimento numero dei giocatori e creazione lista dei giocatori
	Giocatore** listaGiocatori = creaGiocatori();

	//creazione del tabellone, controllo dell'integrita di quest'ultimo e stampa appena viene generato
	creaTabellone();
	integritaTabellone();
	stampaTabellone();

	//creazione e mescolamento dei mazzi carte e domande
	mazzoptr = creaMazzo();
	mazzoptr = mescolaMazzo(mazzoptr, 40);
	mazzoptr = mescolaMazzo(mazzoptr, 40);
	domandeptr = creaMazzoDomande();
	domandeptr = mescolaMazzo(domandeptr, 19);

	/*
	int i =1;
	cartaptr temp = mazzoptr;
	while(temp != NULL){
				cout<<i<<" " <<temp->getNome()<<endl;
				temp=temp->next;
				i++;
		}
 	temp = domandeptr;
	while(temp != NULL){
		cout<<i<<" " <<temp->getDomanda()<<endl;
		temp=temp->next;
		i++;
	}
	*/

	while(pFinita != true){
		flussoGioco(listaGiocatori);
	}
	cout << "PARTITA TERMINATA, ARRIVEDERCI" << endl;
}

void GameController :: creaTabellone(){

	cout << "Creazione tabellone in corso...." << endl;
	sleep(delay);

	int V= 0, A= 0, I= 0, PC= 0, ST= 0,TI= 0;

	numeroCaselle = rand()  % 41+40;
	tabellone[numeroCaselle-1] = new CasellaFinale();
	tabellone[0] = new CasellaIniziale();

	for (int i = 1; i < numeroCaselle-1 ; ++i) {

		int prob = rand() % 100;
		if (prob < 40) {
			tabellone[i] = new CasellaVuota();
			V++;
		}else {
		int	probSpecial = rand() % 100;
			if (probSpecial < 20) {
				tabellone[i] = new CasellaAvanza(rand()%3+1);
				A++;
			} else if (probSpecial < 40 ) {
				tabellone[i] = new CasellaIndietro(rand()%3+1);
				I++;
			}
			else if(probSpecial < 80) {
				tabellone[i] = new CasellaPescaCarta();
				PC++;
			}
			else if(probSpecial < 94){
				tabellone[i] = new CasellaSaltaTurno();
				ST++;
			} else{
				tabellone[i] = new CasellaTornaInizio();
				TI++;
			}
		}
	}

	cout << "Tabellone generato!" << endl;
	sleep(delay);
	cout << "numero caselle totali: " << numeroCaselle << endl;
	cout << "numero caselle vuote: " << V << endl;
	cout << "numero caselle avanza: " << A << endl;
	cout << "numero caselle indietro: " << I << endl;
	cout << "numero caselle Pesca una carta: " << PC << endl;
	cout << "numero caselle salta un turno: " << ST << endl;
	cout << "numero caselle torna all'inizio: " << TI << endl;
	sleep(2);
}


void GameController :: messaggioBenvenuto(){
	cout<<"BENVENUTI AL GIOCO DELL'OCA TEMA MONDIALI" << endl;
}


int GameController :: lanciaDado(){
	int dado = (rand() % 6) + 1;
	cout << "esce il numero: " << dado << endl;
	sleep(delay);
	return dado;
}


void GameController::cambiaPosizione(Giocatore *listaGiocatori[], int pos){
	int nuovaPos = listaGiocatori[attuale]->getPos() + pos;
	if (nuovaPos > numeroCaselle -1){
		nuovaPos = (numeroCaselle-1)-(nuovaPos-(numeroCaselle-1));
	}
	if(nuovaPos < 0){
		nuovaPos = 0;
	}
	listaGiocatori[attuale]->setPos(nuovaPos);
	cout << listaGiocatori[attuale]->getNome() << " va alla posizione: " << listaGiocatori[attuale]->getPos() << endl;
	sleep(delay);
	eseguiEffetto(listaGiocatori);
}


void GameController::stampaTabellone(){
	cout<< endl << "Tabellone:" << endl;
	for (int i = 0; i < numeroCaselle; ++i) {
		cout <<i << ". "<< tabellone[i]->nome << endl;
	}
	cout << endl;
	sleep(delay);
}


void GameController::integritaTabellone(){
	/*
	 * verifica che non ci siano serie troppo lunghe di caselle torna indietro
	 *  e torna inizio, altrimenti ricrea il tabellone
	 */
	int conta = 0;
	for (int i = 0; i < numeroCaselle; ++i) {
		if (tabellone[i]->nome == "Casella Torna Indietro"|| tabellone[i]->nome == "Casella Torna Inizio"){
			conta ++;
		}else {
			conta = 0;
		}
		if (conta > 4){
			cout << "Tabellone non integro, da ricreare!" << endl;
			sleep(delay);
			creaTabellone();
			i = 0;
		}
	}
	//controlla che le caselle avanza finiscano in caselle vuote o alla casella finale
	for (int i = 0; i < numeroCaselle; ++i) {
		if (tabellone[i]->nome != "Casella Avanza") {
			continue;
		}                    //per getMOve
		CasellaAvanza* av = (CasellaAvanza*) tabellone[i];
		int nuovoMov = 0;
		int mov = av->getMove();
		while  (i+mov>= numeroCaselle||(tabellone[i+mov]->nome != "Casella Vuota"&&tabellone[i+mov]->nome != "Finish")){
			mov = nuovoMov++;
		}
//		cout << "spostamento casella avanza "<< i << " modificato da:"<< av->getMove()<< " a " << mov << endl;
		av->setMove(mov);
	}
	//controlla che le caselle indietro finiscano in caselle vuote o alla casella inizio
	for (int i = 0; i < numeroCaselle; ++i) {
			if (tabellone[i]->nome != "Casella Torna Indietro") {
				continue;
			}
			CasellaIndietro* in = (CasellaIndietro*) tabellone[i];
			int nuovoMov = 0;
			int mov = in->getMove();
			while(i+mov<0||(tabellone[i+mov]->nome != "Casella Vuota"&&tabellone[i+mov]->nome != "Start")){
				mov = nuovoMov--;
			}
		//	cout << "spostamento casella indietro "<< i << " modificato da:"<< in->getMove()<< " a " << mov << endl;
			in->setMove(mov);
	}
}


cartaptr GameController:: creaMazzo(){
//la somma delle carte deve essere sempre 39!

	cout << "Preparazione mazzo carte..."<< endl;
	sleep(delay);

	int nCarteAvanza = 5;
	int nCarteIndietro = 6;
	int nCartaBloccaAvversario = 6;
	int nCarteRitiraDado = 8;
	int nCarteVittoria = 1;
	int nCartaTiraTreDadi = 7;
	int nCartaDimezzaPos = 6;

	cartaptr head = new CartaAvanza("Carta Avanza", 5);
	cartaptr temp = head;

	while(nCarteAvanza > 0){
		temp->next = new CartaAvanza("Carta Avanza", 5);
		temp = temp->next;
		nCarteAvanza--;
	}
	while(nCarteIndietro > 0){
		temp->next = new CartaIndietro("Carta Indietro", 4);
		temp = temp->next;
		nCarteIndietro --;
	}
	while(nCartaBloccaAvversario > 0){
		temp->next = new CartaBloccaAvversario("Carta Blocca l'Avversario");
		temp = temp->next;
		nCartaBloccaAvversario --;
	}
	while(nCarteRitiraDado > 0){
		temp->next = new CartaRitira("Carta Ritira");
		temp = temp->next;
		nCarteRitiraDado --;
	}
	while(nCarteVittoria > 0){
		temp->next = new CartaVittoria("Carta Vittoria");
		temp = temp->next;
		nCarteVittoria--;
	}
	while(nCartaTiraTreDadi > 0){
		temp->next = new CartaTiraTreDadi("Carta Tira Tre Dadi");
		temp=temp->next;
		nCartaTiraTreDadi--;
	}
	while(nCartaDimezzaPos > 0){
			temp->next = new CartaDimezza("Carta Dimezza Posizione");
			temp=temp->next;
			nCartaDimezzaPos--;
		}
	cout << "Mazzo Carte Pronto" << endl << endl;
	sleep(delay);
	return head;
}


cartaptr GameController:: mescolaMazzo (cartaptr head,int numeroCarte){
	cartaptr newHead;
	srand((unsigned int)time(0));
	if (head == NULL || numeroCarte == 0)
		return NULL;
	int thisNodo = (rand() % numeroCarte)+1;
	cartaptr curr =nodoEsimo(head, thisNodo);
	cartaptr pre = nodPrec (head, curr);
	if (pre != NULL)
		pre->next = curr->next;
	else head=head->next;
	curr->next=NULL;
	newHead=curr;
	numeroCarte--;

	int nextNodo;
	cartaptr current;
	cartaptr prec;
	cartaptr temp = newHead;

 	while(numeroCarte > 0){
 		nextNodo = (rand() % numeroCarte)+1;
 		//cout<<nextNodo<<" ";
 		current = nodoEsimo(head, nextNodo);

 		prec = nodPrec(head, current);
 		if (prec!=NULL)
 		prec->next=current->next;
 		else head=head->next;
 		current->next = NULL;
 		temp->next=current;
 		temp=temp->next;
 		numeroCarte--;
 	}
 	return newHead;
}

//funzione metti la testa in fondo e ritorna la nuova testa
/*

 cartaptr GameController:: headLast(cartaptr head){
	if (head == NULL)
	    return NULL;
	cartaptr last=ultimoptr(head);
	if (head == last)
		return head;
	cartaptr temp = head;
	temp= temp->next;
	last->next = head;
	head->next = NULL;
	return temp;
}
*/
//funzione che dato un int ti da l'esimo nodo
cartaptr GameController:: nodoEsimo(cartaptr head, int n){
	if (head==NULL || n==0)
		return NULL;

cartaptr temp = head;
	while(n > 1){
		temp=temp->next;
	    n--;
}
	return temp;
}

//funzione che mi ritorna il puntatore all'ultimo della lista
cartaptr GameController:: ultimoptr(cartaptr head){
	cartaptr temp=head;
	while(temp->next != NULL){
		temp=temp->next;
	}
	return temp;
}

//funzione che ritorna il puntatore al nodo precedente
cartaptr GameController:: nodPrec(cartaptr head, cartaptr current){
if (head==NULL || current==NULL || head==current)
	return NULL;
else{
	cartaptr temp=head;

	while(temp->next != current){
		temp=temp->next;}
return temp;
}}


cartaptr GameController::pescaCarta(cartaptr head){
	cartaptr temp = head;
	cartaptr ultimo = ultimoptr(head);
	head=head->next;
	temp->next = NULL;
	ultimo->next=temp;
	return head;
}


void GameController::setFinita(bool finita) {
	pFinita = finita;
}

void GameController::stampaPosizioni(Giocatore *listaGiocatori[]){
	cout << endl<< "Posizioni:" << endl;
	for (int i = 0; i < numeroGiocatori; ++i) {
		cout << i+1<<". " << listaGiocatori[i]->getNome() << " alla casella: " << listaGiocatori[i]->getPos() << endl;
	}
	cout <<endl;
}


void GameController::prossimoGiocatore(){
	attuale++;
	if(attuale >= numeroGiocatori){
		attuale = 0;
	}
}


void GameController::saltaTurno(Giocatore *listaGiocatori[]){
	listaGiocatori[attuale]->setTurnoBloccato(true);
}


void GameController:: tornaInizio(Giocatore *listaGiocatori[]){
	listaGiocatori[attuale]->setPos(0);
}


void GameController::flussoGioco(Giocatore *listaGiocatori[]){
	cout << endl;
	cout << "Premere un carattere per continuare, [q] per uscire, [t] per stampare il tabellone.(E premere invio) "<< endl;
	cin >> esciOtab;
	if(esciOtab!="q" && esciOtab !="Q"&& esciOtab!="t" &&esciOtab!="T"){
		cout << "Turno di: "<< listaGiocatori[attuale]->getNome() << endl;
		sleep(delay);
		if(!listaGiocatori[attuale]->isTurnoBloccato()){
			cout << listaGiocatori[attuale]->getNome() << " lancia il dado..." << endl;
			sleep(delay);
			int dado = lanciaDado();
			cambiaPosizione(listaGiocatori ,dado);
			stampaPosizioni(listaGiocatori);
			prossimoGiocatore();
		}else{
			cout << listaGiocatori[attuale]->getNome() << " salta un turno" << endl;
			listaGiocatori[attuale]->setTurnoBloccato(false);
			prossimoGiocatore();
		}
	}else if(esciOtab=="T"||esciOtab =="t"){
		stampaTabellone();
		stampaPosizioni(listaGiocatori);
	}
	else {
		while(esciOtab!="s" && esciOtab!="n" && esciOtab!="S" && esciOtab!="N") {
			cout << "Sicuro di voler terminare la partita [s/n]? Tutti i progressi andranno persi" << endl;
			cin >> esciOtab;
			if((esciOtab!="s" && esciOtab!="n" && esciOtab!="S" && esciOtab!="N")){
				cout << "Carattere non corretto!Riprovare" << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		}
		if(esciOtab == "S"|| esciOtab== "s"){
		setFinita(true);
		}
	}
}

Giocatore** GameController::creaGiocatori(){

	//verifica che il l'input dell'utente sia corretto
	while (numeroGiocatori <= 1){
		cout <<"Inserire numero giocatori (almeno 2): " << endl;
		cin >> numeroGiocatori;
		if (!cin.good()){
			cout << "Carattere non valido, inserire un numero!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}else if(numeroGiocatori <=1){
			cout << "Valore non corretto, i giocatori devono essere almeno due!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	//        puntatore al puntatore           //Array di puntatori
	Giocatore** listaGiocatori = new Giocatore*[numeroGiocatori];
	//crea il giocatore e gli da il nome
	for (int i = 0; i < numeroGiocatori; ++i) {
		cout << "inserire nome giocatore: "<< i+1 << endl;
		cin >>nome;
		listaGiocatori[i] = new Giocatore(nome, 0);
	}

	//stampa dei giocatori
	cout << "Lista partecipanti:" << endl;
	for (int var = 0; var < numeroGiocatori; ++var) {
		cout<< var+1<< ". " << listaGiocatori[var]->getNome()   <<  endl;

	}

	//mescolamento dei giocatori
	string risp;
	while(risp!="s" && risp!="n" && risp!="S" && risp!="N"){
		cout << "Vuoi rimescolare l'ordine di gioco? [s/n]" << endl;
		cin >> risp;
		if (risp!="s" && risp!="n" && risp!="S" && risp!="N"){
			cout << "Carattere non corretto!Riprovare" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}

	}
	if(risp == "S"|| risp== "s"){
		cout<< "Rimescolo.."<< endl;
		sleep(1);
		random_shuffle(&listaGiocatori[0], &listaGiocatori[numeroGiocatori]);
	}
	cout << "Lista partecipanti:" << endl;
	for (int i = 0; i < numeroGiocatori; ++i) {
		cout << i+1<< ". " << listaGiocatori[i]->getNome() << endl;
	}
	cout << endl;
	sleep(delay);
	return listaGiocatori;
}


void GameController::bloccaAvversario(Giocatore *listaGiocatori[]){
	stampaPosizioni(listaGiocatori);

	int select = 0;
	while (select<1 || select == attuale+1 || select>numeroGiocatori){

		cout << "Seleziona il numero dell'avversario da bloccare: "<< endl;
		cin >> select;
		if (!cin.good()){
			cout << "Carattere errato, riprovare" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		else if (select<1 || select > numeroGiocatori){
			cout << "Numero non valido, riprovare" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		else if (select == attuale+1){
			cout << "Non ti puoi selezionare da solo!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	listaGiocatori[select -1]->setTurnoBloccato(true);
	cout << listaGiocatori[select -1]->getNome()<< " salterà il prossimo turno!" << endl;
}

//metodo per eseguire l'effetto della casella
void GameController:: eseguiEffetto(Giocatore *listaGiocatori[]){
	cout << tabellone[listaGiocatori[attuale]->getPos()]->nome << "!"<< endl;
	sleep(delay);
	tabellone[listaGiocatori[attuale]->getPos()]->messaggio(listaGiocatori[attuale]);
	sleep(delay);
	tabellone[listaGiocatori[attuale]->getPos()]->effetto(this, listaGiocatori);
	//sleep(1);
}

//effetto di casella pesca carta
void GameController::effettoCarta(cartaptr mazzoptr, Giocatore *listaGiocatori[]){
    cartaptr last = ultimoptr(mazzoptr);
	cout<<"La carta pescata è: "<<last->getNome()<<endl;
	sleep(delay);
	last->messaggio();
	last->effetto(this, listaGiocatori);
	sleep(delay);
}


void GameController::dimezzaPosizione(Giocatore *listaGiocatori[]){
	int nuovoPos = listaGiocatori[attuale]->getPos()/2;
	listaGiocatori[attuale]->setPos(nuovoPos);
	cout << listaGiocatori[attuale]->getNome() << " va alla casella " << nuovoPos << "!" << endl;
	eseguiEffetto(listaGiocatori);
}

void GameController::vinciPartita(Giocatore *listaGiocatori[]){
	int nuovaPos =(numeroCaselle-1) - (listaGiocatori[attuale]->getPos());
	cambiaPosizione(listaGiocatori, nuovaPos);
}


cartaptr GameController:: creaMazzoDomande(){
	cout << "Preparazione mazzo domande.." << endl;
	sleep(delay);
	cartaptr head = new CartaDomanda();
	cartaptr temp = head;
	temp->setDomanda("In che posizione si classificò l'Italia, nel mondiale che ospitò nel 1990?");
	temp->risposta[0]="Prima";
	temp->risposta[1]="Seconda";
	temp->risposta[2]="Terza";
	temp->risposta[3]="Quarta";
	temp->setRispEsatta(3);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("La mascotte del mondiale appena concluso in russia era: ");
	temp->risposta[0]="Un gatto";
	temp->risposta[1]="Un orso";
	temp->risposta[2]="Una tigre";
	temp->risposta[3]="Un lupo";
	temp->setRispEsatta(4);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("L'attuale coppa è stata disegnata da un designer: ");
	temp->risposta[0]="Italiano";
	temp->risposta[1]="Inglese";
	temp->risposta[2]="Francese";
	temp->risposta[3]="Spagnolo";
	temp->setRispEsatta(1);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale nazionale ha raggiunto più volte il podio nella storia dei mondiali?");
	temp->risposta[0]="Brasile";
	temp->risposta[1]="Germania";
	temp->risposta[2]="Russia";
	temp->risposta[3]="Italia";
	temp->setRispEsatta(2);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("In che anno si disputò la prima edizione della coppa del mondo?");
	temp->risposta[0]="1930";
	temp->risposta[1]="1946";
	temp->risposta[2]="1896";
	temp->risposta[3]="1952";
	temp->setRispEsatta(1);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quanto pesa all'incirca la coppa che viene consegnata al paese vincitore?");
	temp->risposta[0]="2 kg";
	temp->risposta[1]="10 kg";
	temp->risposta[2]="6 kg";
	temp->risposta[3]="1 kg";
	temp->setRispEsatta(3);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Dove si disputo l'edizione del 2014?");
	temp->risposta[0]="Germania";
	temp->risposta[1]="Argentina";
	temp->risposta[2]="Russia";
	temp->risposta[3]="Brasile";
	temp->setRispEsatta(4);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quante squadre partecipano alla fase finale del mondiale?");
	temp->risposta[0]="16";
	temp->risposta[1]="48";
	temp->risposta[2]="32";
	temp->risposta[3]="8";
	temp->setRispEsatta(3);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale di queste nazionali non ha mai partecipato alla fase finale di un mondiale?");
	temp->risposta[0]="Panama";
	temp->risposta[1]="Ecuador";
	temp->risposta[2]="Turchia";
	temp->risposta[3]="India";
	temp->setRispEsatta(4);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale di queste nazionali africane raggiunse per prima nella storia, i quarti di finale?");
	temp->risposta[0]="Camerun";
	temp->risposta[1]="Nigeria";
	temp->risposta[2]="Egitto";
	temp->risposta[3]="Senegal";
	temp->setRispEsatta(1);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Nell'edizione del 2006 chi fu l'allenatore che portò l'Italia alla vittoria?");
	temp->risposta[0]="F.Capello";
	temp->risposta[1]="M.Lippi";
	temp->risposta[2]="C.Ancelotti";
	temp->risposta[3]="M.Allegri";
	temp->setRispEsatta(2);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Contro quale squadra Maradona fece il gol soprannominato 'Mano de dios'?");
	temp->risposta[0]="Italia";
	temp->risposta[1]="Spagna";
	temp->risposta[2]="Inghilterra";
	temp->risposta[3]="Usa";
	temp->setRispEsatta(3);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale giocatore ha segnato piu gol complessivi, nella storia dei mondiali?");
	temp->risposta[0]="C.Ronaldo";
	temp->risposta[1]="L.Messi";
	temp->risposta[2]="M.Klose";
	temp->risposta[3]="M.Platini";
	temp->setRispEsatta(3);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Dove si giocheranno i prossimi mondiali del 2022?");
	temp->risposta[0]="Quatar";
	temp->risposta[1]="Francia";
	temp->risposta[2]="Argentina";
	temp->risposta[3]="Giappone";
	temp->setRispEsatta(1);

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale nazionale ha vinto più mondiali?");
	temp->risposta[0]="Italia"                                ;
	temp->risposta[1]="Brasile"                               ;
	temp->risposta[2]="Germania"                              ;
	temp->risposta[3]="Francia"                               ;
	temp->setRispEsatta(2)                                    ;

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Chi è stato il giocatore piu giovane di questi ultimi mondiali?");
	temp->risposta[0]="Iniesta"                                ;
	temp->risposta[1]="Mbappe"                               ;
	temp->risposta[2]="Arzani"                              ;
	temp->risposta[3]="Alli"                               ;
	temp->setRispEsatta(3)                                    ;

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Roger Milla è stato il giocatore piu anziano a segnare in un mondiale, quanti anni aveva quando segno tale gol? ");
	temp->risposta[0]="40"                                ;
	temp->risposta[1]="45"                               ;
	temp->risposta[2]="39"                              ;
	temp->risposta[3]="42"                               ;
	temp->setRispEsatta(4)                                    ;

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale giocatore ha vinto piu coppe del mondo?");
	temp->risposta[0]="Ronado Nazario de Lima"                                ;
	temp->risposta[1]="Pelè"                               ;
	temp->risposta[2]="Beckenbauer"                              ;
	temp->risposta[3]="Maradona"                               ;
	temp->setRispEsatta(2)                                    ;

	temp->next = new CartaDomanda();
	temp=temp->next;
	temp->setDomanda("Quale allenatore ha vinto più coppe del mondo?");
	temp->risposta[0]="Pozzo"                                ;
	temp->risposta[1]="Loew"                               ;
	temp->risposta[2]="Scolari"                              ;
	temp->risposta[3]="Lippi"                               ;
	temp->setRispEsatta(1)                                    ;



	//temp->next = new CartaDomanda;
	//temp=temp->next;
	cout << "Mazzo Domande Pronto" << endl<< endl;
	sleep(delay);
	return head;
}

bool GameController:: rispostaEsatta(){
	cout << endl << domandeptr->getDomanda() << endl;
	sleep(3);
	for (int i = 0; i < 4; ++i) {
		cout << i+1 << ". " << domandeptr->risposta[i]<< endl;
	}
	int risp = 0;
	while (risp<1 || risp>4){
		cout << "Selezionare la risposta corretta[1,2,3,4]" << endl;
		cin >> risp;
		if (!cin.good()){
			cout << "Carattere errato, riprovare" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		else if(risp < 1 || risp>4){
			cout << "Numero non valido, riprovare" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	if (risp == domandeptr->getRispEsatta()){
		cout << "Risposta Corretta!" << endl;
		return true;
	}
	else{
		cout<< "Risposta sbagliata!"<< endl;
		return false;
	}
	return true;
}
