

#ifndef GIOCATORE_GIOCATORE_H_
#define GIOCATORE_GIOCATORE_H_
#include <string>

using namespace std;

class Giocatore {
private:
	string nome;
	int pos;
	bool turnoBloccato = false;

public:
	Giocatore(string nome, int pos);
	const string& getNome() const;
	void setNome(const string& nome);
	int getPos() const;
	void setPos(int pos);
	void setTurnoBloccato(bool turnoBloccato);
	bool isTurnoBloccato() const;
};

#endif /* GIOCATORE_GIOCATORE_H_ */
