#include "Lenhador.h"
using namespace Entidades;
using namespace Personagens;

Lenhador::Lenhador(sf::Vector2f tam_corpo, sf::Vector2f pos) : Inimigo(tam_corpo){
    ID = 3;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(LENHADOR);
    corpo.setTexture(&textura);
}

Lenhador::~Lenhador() {

}
