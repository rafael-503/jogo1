#include "../../stdafx.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

void Jogador::inicializa() {

}

Jogador::Jogador(sf::Vector2f tam_corpo) :
    Personagem(tam_corpo, "Jogador"), vel(10.0f, 10.0f)
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(0.0f, 0.0f);

}
Jogador::~Jogador() {}

void Jogador::executar() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        corpo.move(-vel.x, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        corpo.move(vel.x, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        corpo.move(0.0f, -vel.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        corpo.move(0.0f, vel.y);
    }
}

void Jogador::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades) {
    if (pOutra->getTipo() == "Inimigo")
        cout << "Jogador Colidiu com Inimigo" << endl;
    if (pOutra->getTipo() == "Obstaculo") {
        sf::Vector2f posJogador = getPosition(), posOutro = pOutra->getPosition();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && DistanciaExtremidades.y < 0.0f) {
            if (posJogador.y < posOutro.y)
                corpo.move(0.0f, DistanciaExtremidades.y);
            else
                corpo.move(0.0f, -DistanciaExtremidades.y);
        }
        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && DistanciaExtremidades.x < 0.0f) {
            if (posJogador.x < posOutro.x)
                corpo.move(DistanciaExtremidades.x, 0.0f);
            else
                corpo.move(-DistanciaExtremidades.x, 0.0f);
        }

    }

}



