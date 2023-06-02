#include "Soldado.h"
using namespace Entidades;
using namespace Personagens;


Soldado::Soldado(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), dano(45) {
    ID = 4;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(SOLDADO);
    corpo.setTexture(&textura);
}

Soldado::~Soldado() {

}

void Soldado::danar(Jogador* pJog) {
    if (pJog) {
        if(relogioAtaque.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - dano);
            relogioAtaque.restart();
        }
        cout << pJog->getVida() << endl;
    }
}
