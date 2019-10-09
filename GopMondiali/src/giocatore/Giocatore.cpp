
#include "Giocatore.h"



Giocatore::Giocatore(string nome, int pos){
	this->nome = nome;
	setPos(pos);
}

const string& Giocatore::getNome() const {
	return nome;
}

void Giocatore::setNome(const string& nome) {
	this->nome = nome;
}

int Giocatore::getPos() const {
	return pos;
}

void Giocatore::setTurnoBloccato(bool turnoBloccato) {
	this->turnoBloccato = turnoBloccato;
}

void Giocatore::setPos(int pos) {
	this->pos = pos;
}

bool Giocatore::isTurnoBloccato() const {
	return turnoBloccato;
}
