#include "../../stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "../../Gerenciadores/GerenciadorEstado.h"

using namespace Entidades;
using namespace Personagens;

Gerenciadores::GerenciadorEstado* pEstado = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();

void Jogador::inicializa() {
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam_corpo, const char* text) : Personagem(tam_corpo), vel_padrao(10.0f, 0.0f), forca(2)
{
    ID = 1;
    corpo.setPosition(pos);
    setMassa(60.0f);
    setVelocidade(vel_padrao);

    textura = pGrafico->carregarTextura(text);
    corpo.setTexture(&textura);
    relogioColisao.restart();
}

Jogador::~Jogador() {}

void Jogador::executar() {
    efeitoGravidade();
}

void Jogador::Mover_Se(bool Direita, bool pulo, float velY){
    if(pulo){
        if (!SuspensoNoAR) {
            vel.y = -13.0f;
            mover(0.0f, vel.y);
        }
    }
    else{
        if (Direita)
            mover(vel.x, 0.0f);
        else
            mover(-vel.x, 0.0f);
    }
}


void Jogador::Atacar(Inimigo* pInimigo) {
	if(pInimigo){
        pInimigo->setVida(pInimigo->getVida() - forca);
        setPontuacao(getPontuacao() + 5);
	}
}
