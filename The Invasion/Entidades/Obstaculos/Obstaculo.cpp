#include "../../stdafx.h"
#include "Obstaculo.h"


Entidades::Obstaculos::Obstaculo::Obstaculo(sf::Vector2f tam_corpo, float pos_x, float pos_y):
    Entidade(tam_corpo)
{
    corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(pos_x, pos_y);

}
Entidades::Obstaculos::Obstaculo::~Obstaculo(){

}
void Entidades::Obstaculos::Obstaculo::executar(){

}
