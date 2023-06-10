#include "stdafx.h"
#include  "Ente.h"

Gerenciadores::GerenciadorGrafico* Ente::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

Ente::Ente(): ID(0){}

Ente::~Ente(){}

void Ente::desenhar() {}

int Ente::getID() const{
    return ID;
}
