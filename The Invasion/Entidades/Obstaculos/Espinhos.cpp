#include "Espinhos.h"
using namespace Entidades;
using namespace Obstaculos;

Espinhos::Espinhos(sf::Vector2f tam_corpo, sf::Vector2f pos): Obstaculo(tam_corpo, pos) {
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(ESPINHOS);
    corpo.setTexture(&textura);
}

Espinhos::~Espinhos() {}

void Espinhos::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {}

void Espinhos::executar() {}
