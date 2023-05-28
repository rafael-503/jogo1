#include "../../stdafx.h"
#include "Inimigo.h"
#include "Jogador.h"
#include <math.h>

using namespace Entidades;
using namespace Personagens;


Inimigo::Inimigo(sf::Vector2f tam_corpo) :
    Personagem(tam_corpo), jogador(NULL)
{
    ID = 2;
    corpo.setPosition(300.0f, 100.0f);
    srand(time(NULL));
    move_aleatorio = rand() % 4;
    setMassa(60.0f);
    setVelocidade(sf::Vector2f(3.0f, 10.0f));
    relogioColisao.restart();
}

Inimigo::~Inimigo() {}

void Inimigo::setJogador(Jogador* aux_jogador) {
    jogador = aux_jogador;
}

void Inimigo::persegueJogador(sf::Vector2f posJog, sf::Vector2f posInim) {
    if (posJog.x - posInim.x > 0.0f)
        corpo.move(vel.x, 0.0f);
    else
        corpo.move(-vel.x, 0.0f);
    if(!SuspensoNoAR){
        if (posJog.y - posInim.y > 0.0f)
            corpo.move(0.0f, -vel.y);
        else
            corpo.move(0.0f, vel.y);
    }
}

void Inimigo::moveAleatorio() {
    if (move_aleatorio == 0) // direita
        corpo.move(vel.x, 0.0f);
    else if (move_aleatorio == 1) //esquerda
        corpo.move(-vel.x, 0.0f);
    else if(move_aleatorio == 2) //parado
        corpo.move(0.0f, 0.0f);

    float dt = relogio.getElapsedTime().asSeconds();
    if (dt > 1.0f) {
        move_aleatorio = rand() % 3;
        relogio.restart();
    }
}

void Inimigo::executar() {
    if (jogador) {
        sf::Vector2f pos_jogador, pos_inimigo;
        pos_jogador = jogador->getPosition();
        pos_inimigo = getPosition();

        if (fabs(pos_jogador.x - pos_inimigo.x) <= RAIO_PERSEG_X && fabs(pos_jogador.y - pos_inimigo.y) <= RAIO_PERSEG_Y) {
            persegueJogador(pos_jogador, pos_inimigo);
        }
        else
            moveAleatorio();
        efeitoGravidade();
    }
}

void Inimigo::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {
    
    int ID_aux = pOutra->getID();

    if (ID_aux == 1) {
        Personagem* jogador = dynamic_cast<Personagem*>(pOutra);
        if (jogador) {
            float tempo = relogioColisao.getElapsedTime().asSeconds();
            if (tempo >= 1.8f) {
                jogador->setVida(jogador->getVida() - 10);
                relogioColisao.restart(); 
            }
        }
    }

    if (ID_aux >= 5 && ID_aux <=7) {
        sf::Vector2f posInimigo = getPosition(), posOutro = pOutra->getPosition();
        if (!Colidiu_em_x) {
            if (posInimigo.y < posOutro.y){
                corpo.move(0.0f, DistExt.y);
                SuspensoNoAR = false;
            }
            else
                corpo.move(0.0f, -DistExt.y);
        }
        else    {
            if (posInimigo.x < posOutro.x)
                corpo.move(DistExt.x, 0.0f);
            else
                corpo.move(-DistExt.x, 0.0f);
        }
    }
}
