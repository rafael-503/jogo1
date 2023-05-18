#include "../../stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>



Entidades::Personagens::Personagem::Personagem(sf::Vector2f tam_corpo, string tipo) :
    Entidade(tam_corpo, tipo), colidiu_em_y(false), massa(0), vel(0.0f, 0.0f)
{
}

Entidades::Personagens::Personagem::~Personagem() {}

void Entidades::Personagens::Personagem::efeitoGravidade(){
    float G = 0.01f;
    float aceleracao = G * getMassa();
    float dt = relogio.getElapsedTime().asSeconds();
    vel.y = vel.y + dt*aceleracao;
    //cout << "GRAVIDADE" << endl;
}
void Entidades::Personagens::Personagem::setMassa(float massa_aux){
    massa = massa_aux;
}
float Entidades::Personagens::Personagem::getMassa(){
    return massa;
}
void Entidades::Personagens::Personagem::setVelocidade(sf::Vector2f velocidade){
    vel = velocidade;
}
