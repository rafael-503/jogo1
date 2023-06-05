#include "../../stdafx.h"
#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam_corpo) :
    Entidade(tam_corpo), curador(false)
{
    int nAleatorio = rand() % 10;
    if(nAleatorio == 0)
        curador = true;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo() {

}


void Entidades::Obstaculos::Obstaculo::executar() {

}
