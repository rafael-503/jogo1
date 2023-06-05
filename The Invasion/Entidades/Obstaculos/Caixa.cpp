#include "Caixa.h"
using namespace Entidades;
using namespace Obstaculos;
#include "../Personagens/Inimigo.h"

Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam_corpo): Obstaculo(pos, tam_corpo), peso(100){
    ID = 6;
    corpo.setPosition(pos);
    if(curador)
        textura = pGrafico->carregarTextura(CAIXA2);
    else
        textura = pGrafico->carregarTextura(CAIXA);
	corpo.setTexture(&textura);
	peso = rand() % 500;
}

Caixa::~Caixa() {}


void Caixa::executar() {
    efeitoGravidade();
}

void Caixa::obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X){
    if (pJog) {
        /// Regra de três basica que define a porcentagem do peso da caixa no peso total 100 é o peso do jogador
        /// quanto mais pesada caixa menos ela é empurrada e mais ela empurra o jogador

        float porcenCaixa = peso / (peso + 100.0f);
        float porcenJogador =  1.0f - porcenCaixa;

        /// o quanto a caixa e o jogador são empurrados é inversamente proporcional a suas porcentagens

        sf::Vector2f deltaCaixa(DistExtremidades.x * porcenJogador,DistExtremidades.y * porcenJogador),
            deltaJogador(DistExtremidades.x * porcenCaixa, DistExtremidades.y * porcenCaixa);

        /// Jogador empurra caixa em X e fica em cima dela em Y
        sf::Vector2f posCaixa = getPosition(), posJogador = pJog->getPosition();
        if(colidiu_X){
            if(posCaixa.x > posJogador.x){
                mover(-deltaCaixa.x, 0.0f);
                pJog->mover(deltaJogador.x, 0.0f);
            }
            else{
                mover(deltaCaixa.x, 0.0f);
                pJog->mover(-deltaJogador.x, 0.0f);
            }
        }
        else{
            if (pJog->getPosition().y < getPosition().y){
                pJog->mover(0.0f, DistExtremidades.y);
                pJog->setSuspensoNoAR(false);
            }
            else{
                pJog->mover(0.0f, -DistExtremidades.y);
                // Bateu a cabeça
                if(pJog->getVelocidade().y < 0.0f)
                    pJog->setVelocidade_y(0.0f);
            }
        }
        if(curador && clockInteracao.getElapsedTime().asSeconds() > 5){
            pJog->setVida(pJog->getVida() + 10);
            clockInteracao.restart();
        }
    }

}
void Caixa::obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X){
    ///inimigo não consegue mover a caixa
    if(pInimigo){
        if (!colidiu_X) {
            if (pInimigo->getPosition().y < getPosition().y){
                pInimigo->mover(0.0f, DistExtremidades.y);
                pInimigo->setSuspensoNoAR(false);
            }
            else{
                pInimigo->mover(0.0f, -DistExtremidades.y);
                if(pInimigo->getVelocidade().y < 0.0f)
                    pInimigo->setVelocidade_y(0.0f);
            }

        }
        else {
            if (pInimigo->getPosition().x < getPosition().x)
                pInimigo->mover(DistExtremidades.x, 0.0f);
            else
                pInimigo->mover(-DistExtremidades.x, 0.0f);
        }
    }

    else
        cout << "pInimigo nulo em Obstar da caixa" << endl;

}
void Caixa::obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X){

}


