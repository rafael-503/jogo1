#include "../../stdafx.h"
#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam_corpo) :
  Entidade(tam_corpo), danoso(false){
    int nAleatorio = rand() % 10;
    if(nAleatorio <= 1)
        danoso = true;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo() {}

void Entidades::Obstaculos::Obstaculo::executar() {}