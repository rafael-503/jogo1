#include "Cachorro.h"
using namespace Entidades;
using namespace Personagens;

Cachorro::Cachorro(sf::Vector2f tam_corpo, sf::Vector2f pos) : Inimigo(tam_corpo) {
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(CACHORRO);
    corpo.setTexture(&textura);
}

Cachorro::~Cachorro() {

}