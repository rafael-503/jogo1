#include "GerenciadorEvento.h"
#include "GerenciadorEstado.h"
using namespace Gerenciadores;

GerenciadorEvento* GerenciadorEvento::pEvento = NULL;
GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

GerenciadorEvento::GerenciadorEvento(): pGEstado(pGEstado->getGerenciadorEstado()){}

GerenciadorEvento::~GerenciadorEvento(){}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento(){
    if(pEvento == NULL){
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}

void GerenciadorEvento::executar(){}

void GerenciadorEvento::verificarEventos(){
    sf::Event evento;
    if(pGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            pGrafico->fecharJanela();
    }
    pGEstado->TeclaPressionada(evento.key.code);
}