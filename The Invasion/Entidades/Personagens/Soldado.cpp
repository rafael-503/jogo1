#include "Soldado.h"
using namespace Entidades;
using namespace Personagens;
#include "../../Fases/Fase.h"


Soldado::Soldado(sf::Vector2f pos, Fases::Fase* pFaseAux, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), dano(5), pFase(pFaseAux),
 raioTiroMAX(1100.0f), raioTiroMIN(200.0f)
{
    ID = 4;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(SOLDADO);
    corpo.setTexture(&textura);
}

Soldado::~Soldado() {

}

void Soldado::executar(){
    if (pJogador) {
        sf::Vector2f posJog = pJogador->getPosition(), posSold = getPosition();
        float Dist(sqrt((posJog.x - posSold.x) * (posJog.x - posSold.x) + (posJog.y - posSold.y) * (posJog.y - posSold.y)));
        if(Dist > 700.0f)
            moveAleatorio();
        else
            Afastar_se();

        if(Dist > raioTiroMIN && Dist < raioTiroMAX)
            Atirar();
    }
    else
        cout << "pJogador NULO em soldado" << endl;

    efeitoGravidade();
}
void Soldado::Afastar_se(){
    if(pJogador){
        float DistX(pJogador->getPosition().x - getPosition().x);
        if(DistX > 0.0f)
            mover(-vel.x, 0.0f);
        else
            mover(vel.x, 0.0f);
    }
    else
        cout << "pJogador NULO em soldado" << endl;
}

void Soldado::Atirar(){
    if(pJogador){
        if(pFase){
            if(relogioAtaque.getElapsedTime().asSeconds() > 8.0f){
                pFase->AdicionarProjetil(sf::Vector2f(getPosition().x + corpo.getSize().x, getPosition().y + corpo.getSize().y/2));
                //pFase->AdicionarProjetil(getPosition());
                relogioAtaque.restart();
            }
        }

    }

}
void Soldado::danar(Jogador* pJog) {
    if (pJog) {
        if(relogioAtaque.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - dano);
            relogioAtaque.restart();
        }
    }
}

void Soldado::setFase(Fases::Fase* pFaseAux){
    if(pFaseAux)
        pFase = pFaseAux;
    else
        cout << "Passadp pFase nulo em setFase do soldado" << endl;
}

