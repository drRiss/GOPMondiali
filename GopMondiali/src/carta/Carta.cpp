

#include "Carta.h"

using namespace std;

Carta::Carta() {

}

Carta::~Carta() {
}


const string& Carta::getNome() const {
	return nome;
}

void Carta::setNome(const string& nome) {
	this->nome = nome;
}

const string& Carta::getDomanda() const {
	return domanda;
}

void Carta::setDomanda(const string& domanda) {
	this->domanda = domanda;
}

int Carta::getRispEsatta() const {
	return rispEsatta;
}

void Carta::setRispEsatta(int rispEsatta) {
	this->rispEsatta = rispEsatta;
}
