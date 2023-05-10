#include "../../stdafx.h"
#include "Inimigo.h"
#include "Jogador.h"
#include <math.h>

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo(sf::Vector2f tam_corpo):
    Personagem(tam_corpo), vel(8.0f, 8.0f), jogador(NULL)
{
    corpo.setFillColor(sf::Color::Red);
    corpo.setPosition(100.0f, 100.0f);
    srand(time(NULL));
    move_aleatorio = rand() % 4;
}

Inimigo::~Inimigo(){}

void Inimigo::setJogador(Jogador* aux_jogador) {
    jogador = aux_jogador;
}

void Inimigo::persegueJogador(sf::Vector2f posJog, sf::Vector2f posInim) {
    if (posJog.x - posInim.x > 0.0f)
        corpo.move(vel.x, 0.0f);
    else
        corpo.move(-vel.x, 0.0f);
    if (posJog.y - posInim.y > 0.0f)
        corpo.move(0.0f, vel.y);
    else
        corpo.move(0.0f, -vel.y);
}

void Inimigo::moveAleatorio(){
    if (move_aleatorio == 0)
        corpo.move(vel.x, 0.0f);
    else if (move_aleatorio == 1)
        corpo.move(-vel.x, 0.0f);
    else if (move_aleatorio == 2)
        corpo.move(0.0f, vel.y);
    else if (move_aleatorio == 3)
        corpo.move(0.0f, -vel.y);
    
    float dt = relogio.getElapsedTime().asSeconds();
    if (dt > 1.0f) {
        move_aleatorio = rand() % 4;
        relogio.restart();
    }
}

void Inimigo::executar(){
    if(jogador){
        sf::Vector2f pos_jogador, pos_inimigo;
        pos_jogador = jogador->getPosition();
        pos_inimigo = getPosition();

        if (fabs(pos_jogador.x - pos_inimigo.x) <= RAIO_PERSEG_X && fabs(pos_jogador.y - pos_inimigo.y) <= RAIO_PERSEG_Y) {
            persegueJogador(pos_jogador, pos_inimigo);
        }
        else
            moveAleatorio();
    }
}