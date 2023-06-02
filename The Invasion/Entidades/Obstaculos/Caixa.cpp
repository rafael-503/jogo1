#include "Caixa.h"
using namespace Entidades;
using namespace Obstaculos;
#include "../Personagens/Inimigo.h"

Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam_corpo): Obstaculo(pos, tam_corpo), velX(7.0f) {
  ID = 6;
  corpo.setPosition(pos);
	textura = pGrafico->carregarTextura(CAIXA);
	corpo.setTexture(&textura);
}

Caixa::~Caixa() {}


void Caixa::executar() {
    efeitoGravidade();

}

void Caixa::obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X){
    if (pJog) {

        /// Jogador empurra caixa em x e fica em cima dela em Y
        sf::Vector2f posCaixa = getPosition(), posJogador = pJog->getPosition();
        if(colidiu_X){
            if(posCaixa.x > posJogador.x)
                mover(-DistExtremidades.x, 0.0f);
            else
                mover(DistExtremidades.x, 0.0f);
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

