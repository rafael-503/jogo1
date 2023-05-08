#include "../../stdafx.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;




Jogador::Jogador(sf::Vector2f tam_corpo):
    Personagem(tam_corpo), vel(15.0f, 15.0f)
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(0.0f, 0.0f);

}
Jogador::~Jogador(){

}


void Jogador::executar(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        corpo.move(-vel.x, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        corpo.move(vel.x, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        corpo.move(0.0f, -vel.y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        corpo.move(0.0f, vel.y);
    }


}





