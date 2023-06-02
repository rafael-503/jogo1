#include "Lenhador.h"
using namespace Entidades;
using namespace Personagens;

Lenhador::Lenhador(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), forca(30){
    ID = 3;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(LENHADOR);
    corpo.setTexture(&textura);
}

Lenhador::~Lenhador() {

}

void Lenhador::danar(Jogador* pJog) {
    if (pJog) {
        if(relogioAtaque.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - forca);
            relogioAtaque.restart();
        }
    }
}

