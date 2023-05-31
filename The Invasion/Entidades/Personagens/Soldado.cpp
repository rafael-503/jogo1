#include "Soldado.h"
using namespace Entidades;
using namespace Personagens;


Soldado::Soldado(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo) {
    ID = 4;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(SOLDADO);
    corpo.setTexture(&textura);
    
}

Soldado::~Soldado() {

}
