#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f pos) : Obstaculo(pos){}

Plataforma::~Plataforma() {}

void Plataforma::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {}

void Plataforma::executar() {}