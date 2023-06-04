#include "../../stdafx.h"
#include "Inimigo.h"
#include "Jogador.h"
#include <math.h>

using namespace Entidades;
using namespace Personagens;

std::pair<Jogador*, Jogador*> Inimigo::pJogadores(NULL, NULL);
Inimigo::Inimigo(sf::Vector2f tam_corpo) :
    Personagem(tam_corpo), relogioAtaque()
{
    ID = 2;
    corpo.setPosition(300.0f, 100.0f);
    srand(time(NULL));
    move_aleatorio = rand() % 4;
    setMassa(60.0f);
    setVelocidade(sf::Vector2f(3.0f, 10.0f));
    relogioColisao.restart();
}

Inimigo::~Inimigo() {
}

void Inimigo::setPairpJogadores(Jogador* pJog_1, Jogador* pJog_2){
    pJogadores.first = pJog_1;
    pJogadores.second = pJog_2;

}
void Inimigo::limparPairpJogadores(){
    pJogadores.first = NULL;
    pJogadores.second = NULL;

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
        corpo.move(vel.x/2, 0.0f);
    else if (move_aleatorio == 1 || move_aleatorio == 4) //esquerda
        corpo.move(-vel.x/2, 0.0f);
    else if(move_aleatorio == 2) //parado
        corpo.move(0.0f, 0.0f);

    float dt = relogio.getElapsedTime().asSeconds();
    if (dt > 1.0f) {
        move_aleatorio = rand() % 4;
        relogio.restart();
    }
}

void Inimigo::executar() {
    if (pJogadores.first || pJogadores.second) {
        sf::Vector2f pos_jogador, pos_inimigo;
        if(pJogadores.first && pJogadores.second){
            if(pJogadores.first->getPosition().x - getPosition().x < pJogadores.second->getPosition().x - getPosition().x)
                pos_jogador = pJogadores.first->getPosition();
            else
                pos_jogador = pJogadores.second->getPosition();
        }
        else if(pJogadores.first){
            pos_jogador = pJogadores.first->getPosition();
        }
        else
            pos_jogador = pJogadores.second->getPosition();


        pos_inimigo = getPosition();

        if (fabs(pos_jogador.x - pos_inimigo.x) <= RAIO_PERSEG_X && fabs(pos_jogador.y - pos_inimigo.y) <= RAIO_PERSEG_Y) {
            persegueJogador(pos_jogador, pos_inimigo);
        }
        else
            moveAleatorio();
        efeitoGravidade();
    }
    else
        cout << "pJogadores NULOS em Inimigo::executar" << endl;
}
