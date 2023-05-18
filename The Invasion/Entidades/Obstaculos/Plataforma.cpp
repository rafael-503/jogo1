#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f tam_corpo, sf::Vector2f pos) : Obstaculo(tam_corpo, pos){
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura("The Invasion/assets/obstaculos/plataformas/plataforma1.png");
    corpo.setTexture(&textura);
}

Plataforma::~Plataforma() {}

void Plataforma::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {}

void Plataforma::executar() {}