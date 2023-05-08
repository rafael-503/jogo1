#include "../stdafx.h"
#include "Entidade.h"
using namespace Entidades;


Entidade::Entidade(sf::Vector2f tam_corpo):
    corpo(tam_corpo)
{

}
Entidade::~Entidade(){

}
sf::RectangleShape Entidade::getCorpo(){
    return corpo;
}

const sf::Vector2f Entidade::getPosition() const{
    return corpo.getPosition();
}

