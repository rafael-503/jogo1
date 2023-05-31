#include "Projetil.h"
#define VEL_INICIAL 10.0f
using namespace Entidades;

Projetil::Projetil(sf::Vector2f posInimigo, Personagens::Jogador* pJogador1, Personagens::Jogador* pJogador2):
     Entidade(sf::Vector2f(10.0f, 5.0f)), vel_projetil(10.0f), pPerseguido(NULL)
{
    corpo.setPosition(posInimigo);
    if(pJogador1 && pJogador2){
        if(fabs(corpo.getPosition().x - pJogador1->getPosition().x) < fabs(corpo.getPosition().x - pJogador2->getPosition().x))
            pPerseguido = pJogador1;
        else
            pPerseguido = pJogador2;
    }
    else if(pJogador1)
        pPerseguido = pJogador1;
    else if(pJogador2)
        pPerseguido = pJogador2;
    else
        cout << "Jogadores Nulos em Projetil" << endl;

}
Projetil::~Projetil(){

}
void Projetil::executar(){
    if(pPerseguido){
        sf::Vector2f Direcao(pPerseguido->getPosition().x - corpo.getPosition().x, pPerseguido->getPosition().y - corpo.getPosition().y);

        ///transdorma Direcao em um vetor unitario para multiplicar por velocidade e ir nessa direção
        sf::Vector2f DirecaoUnitaria(Direcao.x / sqrt(Direcao.x*Direcao.x + Direcao.y*Direcao.y), Direcao.y / sqrt(Direcao.x*Direcao.x + Direcao.y*Direcao.y));
        corpo.move(DirecaoUnitaria.x * vel_projetil, DirecaoUnitaria.y * vel_projetil);
    }
    else
        cout << "pPerseguido Nulo em Projetil" << endl;

}
