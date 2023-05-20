#include "Caixa.h"
using namespace Entidades;
using namespace Obstaculos;


Caixa::Caixa(sf::Vector2f tam_corpo, sf::Vector2f pos): Obstaculo(tam_corpo, pos) {
  ID = 6;
  corpo.setPosition(pos);
	textura = pGrafico->carregarTextura(CAIXA);
	corpo.setTexture(&textura);
}

Caixa::~Caixa() {}

void Caixa::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {


    int ID_aux = pOutra->getID();
    //colidiu com obstaculo


    if(ID_aux >= 5 && ID_aux <=7){
        sf::Vector2f posCaixa = getPosition(), posOutra = pOutra->getPosition();
        if(!Colidiu_em_x){
            corpo.move(0.0f, DistExt.y);
            SuspensoNoAR = false;
        }
        else{
            if(posCaixa.x > posOutra.x)
                corpo.move(0.0f, DistExt.x);
            else
                corpo.move(0.0f, DistExt.x);
        }

    }

}

void Caixa::executar() {
    efeitoGravidade();

}