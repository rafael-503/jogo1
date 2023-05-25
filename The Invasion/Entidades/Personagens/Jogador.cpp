#include "../../stdafx.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

void Jogador::inicializa() {
}

Jogador::Jogador(sf::Vector2f tam_corpo) :
    Personagem(tam_corpo)
{
    ID = 1;
    //corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(10.0f, 0.0f);
    setMassa(60.0f);
    setVelocidade(sf::Vector2f(10.0f, 0.0f));

    textura = pGrafico->carregarTextura(JOGADOR);
    corpo.setTexture(&textura);
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

    //ID_aux recebe id da entidade com qual esta colidindo
    int ID_aux = pOutra->getID();
    if (ID_aux == 2)
        cout << "Jogador Colidiu com Inimigo" << endl;
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
        if (ID_aux == 7) {
            float tempo = relogio.getElapsedTime().asSeconds();
            if (tempo > 0.1f) {
                setVida(getVida() - 10);
                cout << getVida() << endl;
            }
            relogio.restart();
            
        }

            //cout << "ESPINHOS" << endl;
    }

}



