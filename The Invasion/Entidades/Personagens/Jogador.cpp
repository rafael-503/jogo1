#include "../../stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "../../Gerenciadores/GerenciadorEstado.h"

using namespace Entidades;
using namespace Personagens;

Gerenciadores::GerenciadorEstado* pEstado = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();

void Jogador::inicializa() {
}

Jogador::Jogador(sf::Vector2f tam_corpo, sf::Vector2f pos) : Personagem(tam_corpo)
{
    ID = 1;
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
            vel.y = -13.0f;
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
    /*
    if (ID_aux == 2) { // colisao generia do inimigo
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
    }*/

    if (ID_aux == 3) { // colisao com o cachorro e o lenhador
        Inimigo* inimigo = dynamic_cast<Inimigo*>(pOutra);
        if (tempo > 1.5f && inimigo->getVida() > 0) {
            inimigo->setVida(inimigo->getVida() - 50);
            setPontuacao(getPontuacao()+5);
            cout << getPontuacao() << endl;
            relogioColisao.restart();
        }
    }

    if (ID_aux == 4) { // colisao com o soldado
	    Inimigo* inimigo = dynamic_cast<Inimigo*>(pOutra);
        if (tempo > 1.5f && inimigo->getVida() > 0) {
            inimigo->setVida(inimigo->getVida() - 30);
            setPontuacao(getPontuacao() + 30);
            relogioColisao.restart();
            if (inimigo->getVida() <= 0) {
                cout << "Proxima fase" << endl;
                pEstado->trocarFase(false);
                //pEstado->setEstadoAtual("EstadoJogar");
                //pEstado->setProximaFase();
            }
        }
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
        else {
            if(ID_aux != 6){
                if (posJogador.x < posOutro.x)
                    corpo.move(DistExt.x, 0.0f);
                else
                    corpo.move(-DistExt.x, 0.0f);
            }
        }

        if(ID_aux == 5) // PLATAFORMA
        if(ID_aux == 6) // CAIXA

        if (ID_aux == 7) { // ESPINHOS
            /*
            if (tempo > 1.8f) {
                setVida(getVida() - 10);
                cout << getVida() << endl;
                relogioColisao.restart();
            }*/
        }
    }
}
