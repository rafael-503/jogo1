#include "Projetil.h"
using namespace Entidades;

Projetil::Projetil(sf::Vector2f tam_corpo, sf::Vector2f pos_inicial): Entidade(tam_corpo){
    corpo.setPosition(pos_inicial);

}
Projetil::~Projetil(){

}
