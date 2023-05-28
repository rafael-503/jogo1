#include "../../stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"
using namespace Entidades;
using namespace Personagens;

void Jogador::inicializa() {
}

Jogador::Jogador(sf::Vector2f tam_corpo, sf::Vector2f pos) :
    Personagem(tam_corpo)
{
    ID = 1;
    //corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(pos);
    setMassa(60.0f);
    setVelocidade(sf::Vector2f(10.0f, 0.0f));

    textura = pGrafico->carregarTextura(JOGADOR);
    corpo.setTexture(&textura);
    relogioColisao.restart();
}

Jogador::~Jogador() {}

void Jogador::executar() {
    efeitoGravidade();
}

void Jogador::move(bool Direita, bool pulo){
    if(pulo){
        if (!SuspensoNoAR) {
            vel.y = -10.0f;
            corpo.move(0.0f, vel.y);
        }
    }
    else{
        if (Direita)
            corpo.move(vel.x, 0.0f);
        else
            corpo.move(-vel.x, 0.0f);
    }
}


void Jogador::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {
    float tempo = relogioColisao.getElapsedTime().asSeconds();

    //ID_aux recebe id da entidade com qual esta colidindo
    int ID_aux = pOutra->getID();
    if (ID_aux == 2) { // INIMIGO
        cout << "Jogador Colidiu com Inimigo" << endl;
        if (tempo > 1.0f) {
            //setVida(getVida() - 10);
            //cout << getVida() << endl;
            Inimigo* inimigo = dynamic_cast<Inimigo*>(pOutra);
            inimigo->setVida(inimigo->getVida() - 100);
            cout << inimigo->getVida() << endl;
            //atacar(inimigo);
        }
        relogio.restart();
    }
    if (ID_aux >= 5 && ID_aux <=7) {
        sf::Vector2f posJogador = getPosition(), posOutro = pOutra->getPosition();

        //colisão
        if (!Colidiu_em_x) {
            if (posJogador.y < posOutro.y){
                corpo.move(0.0f, DistExt.y);
                SuspensoNoAR = false;
            }
            else{
                corpo.move(0.0f, -DistExt.y);
                //bateu a cabeça
                if (vel.y < 0.0f)
                    vel.y = 0.0f;
            }
        }
        else    {
            if(ID_aux != 6){
                if (posJogador.x < posOutro.x)
                    corpo.move(DistExt.x, 0.0f);
                else
                    corpo.move(-DistExt.x, 0.0f);
            }

        }

        if(ID_aux == 5)
            //cout << "PLATAFORMA" << endl;
        if(ID_aux == 6)
            cout << "CAIXA" << endl;
        if (ID_aux == 7) { // ESPINHOS
            //float tempo = relogio.getElapsedTime().asSeconds();
            if (tempo > 1.8f) {
                setVida(getVida() - 10);
                cout << getVida() << endl;
                relogioColisao.restart();
            }
            //relogio.restart();
        }
    }

}

void Jogador::atacar(Inimigo* pInimigo) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (pInimigo) {
        pInimigo->setVida(pInimigo->getVida() - 100);
        cout << pInimigo->getVida() << endl;
        cout << "Ataque" << endl;
        }
    }
}