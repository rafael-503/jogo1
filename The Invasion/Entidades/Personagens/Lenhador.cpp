#include "Lenhador.h"
using namespace Entidades;
using namespace Personagens;

Lenhador::Lenhador(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), forca(10){
    ID = 3;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(LENHADOR);
    corpo.setTexture(&textura);
}

Lenhador::~Lenhador() {

}

void Lenhador::danar(Jogador* pJog) {
	pJog->setVida(pJog->getVida() - forca);
}