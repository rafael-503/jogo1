#include "Cachorro.h"
using namespace Entidades;
using namespace Personagens;

Cachorro::Cachorro(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), manso(true){
    ID = 3;
    corpo.setPosition(pos);

    srand(std::time(0));
    int num = rand() % 100;
    //cout << num << endl;
    if (num %2 == 0)
        manso = false;

    if (manso) {
        textura = pGrafico->carregarTextura(CACHORRO2);
        corpo.setTexture(&textura);
    }
    else {
        textura = pGrafico->carregarTextura(CACHORRO);
        corpo.setTexture(&textura);
    }
}

Cachorro::~Cachorro() {

}

void Cachorro::danar(Jogador* pJog) {
    if (pJog) {
        if(relogioAtaque.getElapsedTime().asSeconds() > 5.0f){
            if (manso)
                pJog->setVida(pJog->getVida() - 3);
            else
                pJog->setVida(pJog->getVida() - 15);
            relogioAtaque.restart();
        }
    }
}
