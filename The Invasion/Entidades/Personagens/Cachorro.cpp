#include "Cachorro.h"
using namespace Entidades;
using namespace Personagens;

Cachorro::Cachorro(sf::Vector2f tam_corpo, sf::Vector2f pos) : Inimigo(tam_corpo) {
    ID = 3;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(CACHORRO);
    corpo.setTexture(&textura);
}

Cachorro::~Cachorro() {

}
