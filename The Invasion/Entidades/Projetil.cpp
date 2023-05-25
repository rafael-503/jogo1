#include "Projetil.h"
#define VEL_INICIAL 10.0f
using namespace Entidades;

Projetil::Projetil(sf::Vector2f tam_corpo, sf::Vector2f pos, sf::Vector2f distancia): Entidade(tam_corpo)
{
    corpo.setPosition(pos);
    float G = 1.0f;
    float vel_y = (float) sqrt(2*G*distancia.y);
    sf::Vector2f vel_inicial((float) sqrt((VEL_INICIAL*VEL_INICIAL) - (vel_y*vel_y)), vel_y);
   // if (distancia.x > 0.0f)
    setVelocidade(vel_inicial);

}
Projetil::~Projetil(){

}
void Projetil::executar(){
    efeitoGravidade();

    corpo.move(vel);
}
