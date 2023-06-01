#include "Plataforma.h"
#include "../Personagens/Jogador.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo, const char* text) : Obstaculo(pos, tam_corpo), velY(-1.0f){
    ID = 5;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(text);
    corpo.setTexture(&textura);
}

Plataforma::~Plataforma() {}

void Plataforma::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {}

void Plataforma::executar() {}

void Plataforma::obstar(Entidades::Personagens::Jogador* pJog) {
    if (pJog)
        pJog->move(false, true, velY); // verificar a velocidade se e muito alta
}