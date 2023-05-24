#include "GerenciadorEvento.h"
using namespace Gerenciadores;

GerenciadorEvento* GerenciadorEvento::pEvento = NULL;
GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

GerenciadorEvento::GerenciadorEvento(){


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
void GerenciadorEvento::setJogador(Entidades::Personagens::Jogador* pJogadorAux){
    pJogador = pJogadorAux;
}
void GerenciadorEvento::verificarEventos(){
    sf::Event evento;
    if(pJogador){
        if(pGrafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pJogador->move(false, false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pJogador->move(true, false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            pJogador->move(false, true);

    }
}
