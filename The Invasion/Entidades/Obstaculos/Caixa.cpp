#include "Caixa.h"
using namespace Entidades;
using namespace Obstaculos;

Caixa::Caixa(sf::Vector2f tam_corpo, sf::Vector2f pos): Obstaculo(tam_corpo, pos) {
	corpo.setPosition(pos);
	textura = pGrafico->carregarTextura(CAIXA);
	corpo.setTexture(&textura);
}

Caixa::~Caixa() {}

void Caixa::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {}

void Caixa::executar() {}
