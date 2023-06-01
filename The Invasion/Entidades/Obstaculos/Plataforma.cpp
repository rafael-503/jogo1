#include "Plataforma.h"
#include "../Personagens/Jogador.h"
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo, const char* text) : Obstaculo(pos, tam_corpo), velY(-1.0f){
    ID = 5;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(text);
    corpo.setTexture(&textura);
}

Plataforma::~Plataforma() {}

void Plataforma::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {
    int ID_aux = pOutra->getID();
    float tempo = relogio.getElapsedTime().asSeconds();

	if (ID_aux == 1) { // colisao da plataforma com o jogador
        if (tempo > 2.0f) {
        Entidades::Personagens::Jogador* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(pOutra);
    	obstar(jogador);
        relogio.restart();        
        }
    }
}

void Plataforma::executar() {}

void Plataforma::obstar(Entidades::Personagens::Jogador* pJog) {
    if (pJog)
        pJog->move(false, true, velY); // verificar a velocidade se e muito alta
    cout << "empurrou o jogador para cima" << endl;
}