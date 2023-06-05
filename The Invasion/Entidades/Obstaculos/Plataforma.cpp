#include "Plataforma.h"
#include "../Personagens/Jogador.h"
#include "../Personagens/Inimigo.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo, const char* text) : Obstaculo(pos, tam_corpo), velY(-1.0f), danoso(false){
    ID = 5;
    corpo.setPosition(pos);

    if (num <=15) {
        danoso = true;
    }
    relogioDanoso.restart();

    if(danoso)
        textura = pGrafico->carregarTextura(PLATAFORMA4);
    else 
        textura = pGrafico->carregarTextura(text);

    corpo.setTexture(&textura);
    relogioDanoso.restart();
}

Plataforma::~Plataforma() {}


void Plataforma::executar() {}

void Plataforma::obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X) {
    ///Plataforma colidi igual com todos Personagens
    if (pJog) {
        if (danoso && relogioDanoso.getElapsedTime().asSeconds() > 10.0f) {
            pJog->setVida(pJog->getVida() - 4);
        	relogioDanoso.restart();
        }
        ColidirPlataforma(static_cast<Entidade*> (pJog), DistExtremidades, colidiu_X);
    }
    
    
    else
        cout << "pJog nulo em Obstar do Plataforma" << endl;

}
void Plataforma::obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X){
    ///Plataforma colidi igual com todos Personagens
    if(pInimigo)
        ColidirPlataforma(static_cast<Entidade*> (pInimigo), DistExtremidades, colidiu_X);
    else
        cout << "pInimigo nulo em Obstar do Plataforma" << endl;
}
void Plataforma::obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X){
    ///Plataforma colidi com a caixa como se fosse um Personagem
    if(pObs->getID() == 6){
        if(pObs)
            ColidirPlataforma(static_cast<Entidade*> (pObs), DistExtremidades, colidiu_X);
        else
            cout << "pObs nulo em Obstar do Plataforma" << endl;
    }
}
void Plataforma::ColidirPlataforma(Entidade* pEnti, sf::Vector2f DistExtremidades, bool colidiu_X){
    if(pEnti){
        if (!colidiu_X) {
            if (pEnti->getPosition().y < getPosition().y){
                pEnti->mover(0.0f, DistExtremidades.y);
                pEnti->setSuspensoNoAR(false);
            }
            else{
                pEnti->mover(0.0f, -DistExtremidades.y);
                if(pEnti->getVelocidade().y < 0.0f)
                    pEnti->setVelocidade_y(0.0f);
            }

        }
        else {
            if (pEnti->getPosition().x < getPosition().x)
                pEnti->mover(DistExtremidades.x, 0.0f);
            else
                pEnti->mover(-DistExtremidades.x, 0.0f);
        }
    }

    else
        cout << "pEnti nulo em ColidirPlataforma do Plataforma" << endl;

}

