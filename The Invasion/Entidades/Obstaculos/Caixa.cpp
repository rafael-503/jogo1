#include "Caixa.h"
using namespace Entidades;
using namespace Obstaculos;


Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam_corpo): Obstaculo(pos, tam_corpo), velX(7.0f) {
  ID = 6;
  corpo.setPosition(pos);
	textura = pGrafico->carregarTextura(CAIXA);
	corpo.setTexture(&textura);
}

Caixa::~Caixa() {}

void Caixa::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {


    int ID_aux = pOutra->getID();
    //colidiu com obstaculo
    //colisão com jogador
    if(ID_aux == 1 && Colidiu_em_x){
        sf::Vector2f posCaixa = getPosition(), posOutra = pOutra->getPosition();
        if(posCaixa.x > posOutra.x)
            corpo.move(-DistExt.x, 0.0f);
        else
            corpo.move(DistExt.x, 0.0f);

    }

    else if(ID_aux >= 5 && ID_aux <=7){
        sf::Vector2f posCaixa = getPosition(), posOutra = pOutra->getPosition();
        if(!Colidiu_em_x){
            corpo.move(0.0f, DistExt.y);
            SuspensoNoAR = false;
        }
        else{
           if(posCaixa.x > posOutra.x)
                corpo.move(-DistExt.x, 0.0f);
            else
                corpo.move(DistExt.x, 0.0f);
        }

    }

}

void Caixa::executar() {
    efeitoGravidade();

}

void Caixa::obstar(Entidades::Personagens::Jogador* pJog) {
    if (pJog) {
		pJog->move(true, false); // velocidade x diminui ao colidir com a caixa
        pJog->setVelocidade(sf::Vector2f(velX, pJog->getVelocidade().y));
    }
}
