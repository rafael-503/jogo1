#include "Cachorro.h"
using namespace Entidades;
using namespace Personagens;

Cachorro::Cachorro(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), manso(true){
    ID = 3;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(CACHORRO);
    corpo.setTexture(&textura);
    int num = rand() % 2;
    if (num == 0)
        manso = true;
}

Cachorro::~Cachorro() {

}

void Cachorro::danar(Jogador* pJog) {
    if (manso)
		pJog->setVida(pJog->getVida() - 4);
    else
		pJog->setVida(pJog->getVida() - 8);
}