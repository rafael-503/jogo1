#include "Espinhos.h"
#include "../Personagens/Jogador.h"

using namespace Entidades;
using namespace Obstaculos;

Espinhos::Espinhos(sf::Vector2f tam_corpo, sf::Vector2f pos): Obstaculo(tam_corpo, pos) {
    ID = 7;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(ESPINHOS);
    corpo.setTexture(&textura);
    relogio.restart();
}


Espinhos::~Espinhos() {}

void Espinhos::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {
    int ID_aux = pOutra->getID();
    float tempo = relogio.getElapsedTime().asSeconds();

    if (ID_aux == 1) { // colisao do espinho com o jogador
        Entidades::Personagens::Jogador* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(pOutra);

        if (tempo > 1.8f && jogador->getVida() > 0) {
            jogador->setVida(jogador->getVida() - 5);
            relogio.restart();
        }
    }
}

void Espinhos::executar() {}