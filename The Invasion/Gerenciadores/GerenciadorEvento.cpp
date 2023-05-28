#include "GerenciadorEvento.h"
#include "GerenciadorEstado.h"
using namespace Gerenciadores;


GerenciadorEvento* GerenciadorEvento::pEvento = NULL;
GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

GerenciadorEvento::GerenciadorEvento(): pGEstado(pGEstado->getGerenciadorEstado()){

}

GerenciadorEvento::~GerenciadorEvento(){

}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento(){
    if(pEvento == NULL){
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}

void GerenciadorEvento::executar(){

}

void GerenciadorEvento::verificarEventos(){
    sf::Event evento;
    if(pGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            pGrafico->fecharJanela();
    }
    //if(evento.type == sf::Event::KeyPressed)
        pGEstado->TeclaPressionada(evento.key.code);
    /*
    if(pJogador){
        if(pGrafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            setPosicaoJogador(pJogador->getPosition());
            pJogador->move(false, false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            setPosicaoJogador(pJogador->getPosition());
            pJogador->move(true, false);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            pJogador->move(false, true);
    }
    */
}

