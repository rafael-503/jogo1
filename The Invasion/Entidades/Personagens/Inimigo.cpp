#include "../../stdafx.h"
#include "Inimigo.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;


Inimigo::Inimigo(sf::Vector2f tam_corpo):
    Personagem(tam_corpo), vel(15.0f, 15.0f)
{
    corpo.setFillColor(sf::Color::Red);
    corpo.setPosition(100.0f, 100.0f);

}
Inimigo::~Inimigo(){

}


void Inimigo::executar(){
    if(jogador){
        sf::Vector2f pos_jogador, pos_inimigo;
        pos_jogador = jogador->getPosition();
        pos_inimigo = getPosition();
        if(pos_inimigo.x - pos_jogador.x > 0.0f)
            corpo.move(-vel.x, 0.0f);
        else
            corpo.move(vel.x, 0.0f);
        if(pos_inimigo.y - pos_jogador.y < 0.0f)
            corpo.move(0.0f, vel.y);
        else
            corpo.move(0.0f, -vel.y);

    }
}

void Inimigo::setJogador(Jogador* aux_jogador){
    jogador = aux_jogador;
}





