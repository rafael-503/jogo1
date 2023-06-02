#include "Espinhos.h"
#include "../Personagens/Jogador.h"

using namespace Entidades;
using namespace Obstaculos;

Espinhos::Espinhos(sf::Vector2f pos, sf::Vector2f tam_corpo): Obstaculo(pos, tam_corpo), dano(10), RelogioEspinho() {
    ID = 7;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(ESPINHOS);
    corpo.setTexture(&textura);
    relogio.restart();
}

Espinhos::~Espinhos() {

}

void Espinhos::executar() {

}

void Espinhos::obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X){

    /// empurra o Jogador para fora de si devagar e o da dano a cada 5 seguundos após entrar
    if(pJog){
        if(RelogioEspinho.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - dano);
            RelogioEspinho.restart();
        }
        if (!colidiu_X) {
            if (pJog->getPosition().y < getPosition().y){
                pJog->mover(0.0f, DistExtremidades.y / 100);
                pJog->setSuspensoNoAR(false);
            }
            else{
                pJog->mover(0.0f, -DistExtremidades.y / 100);
                if(pJog->getVelocidade().y < 0.0f)
                    pJog->setVelocidade_y(0.0f);
            }

        }
        else {
            if (pJog->getPosition().x < getPosition().x)
                pJog->mover(DistExtremidades.x / 100, 0.0f);
            else
                pJog->mover(-DistExtremidades.x  / 100, 0.0f);
        }
    }

    else
        cout << "pJog nulo em obstar dos Espinhos" << endl;

}
void Espinhos::obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X){


}
void Espinhos::obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X){

}
