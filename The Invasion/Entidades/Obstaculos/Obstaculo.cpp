#include "../../stdafx.h"
#include "Obstaculo.h"


Entidades::Obstaculos::Obstaculo::Obstaculo(sf::Vector2f tam_corpo, sf::Vector2f pos) :
    Entidade(tam_corpo, "Obstaculo")
{
    //corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura("The Invasion/assets/obstaculos/plataformas/plataforma1.png");
    corpo.setTexture(&textura);

}
Entidades::Obstaculos::Obstaculo::~Obstaculo() {

}
void Entidades::Obstaculos::Obstaculo::executar() {

}
void Entidades::Obstaculos::Obstaculo::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {


}
