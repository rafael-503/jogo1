#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo) : Obstaculo(pos, tam_corpo){
    ID = 5;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(PLATAFORMA);
    corpo.setTexture(&textura);
}

Plataforma::~Plataforma() {}

void Plataforma::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {}

void Plataforma::executar() {}