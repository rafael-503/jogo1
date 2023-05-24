#include "Fase1.h"
using namespace Fases;

Fase1::Fase1() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
	criarPersonagens();
	criarObstaculos();
}

Fase1::~Fase1() {

}

void Fase1::executar() {
	listaPersonagens.executar();
	listaObstaculos.executar();
    pColisao->testa_colisoes();
	listaPersonagens.seDesenhe();
    listaObstaculos.seDesenhe();
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
}

void Fase1::criarPersonagens() {

    Entidades::Personagens::Jogador* pJogador = new Entidades::Personagens::Jogador(sf::Vector2f(80.0f, 80.0f));
    Entidades::Personagens::Soldado* pSoldado = new Entidades::Personagens::Soldado(sf::Vector2f(80.0f, 80.0f), sf::Vector2f(80.0f, 80.0f));

    Entidades::Personagens::Inimigo* pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pSoldado);

    pInimigo->setJogador(pJogador);

    Entidades::Entidade* pEntidade = NULL;

    pColisao->incluiInimigo(pInimigo);
    pEntidade = static_cast<Entidade*> (pJogador);
    listaPersonagens.inserir(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    listaPersonagens.inserir(pEntidade);

    pEventos->setJogador(pJogador);
    pColisao->setJogador(pJogador);
    //pColisao->testa_colisoes(&jogador);
}

void Fase1::criarObstaculos() {
    Entidade* pEntidade = NULL;
    Entidades::Obstaculos::Obstaculo* pObstaculo = NULL;

    pObstaculo = new Entidades::Obstaculos::Plataforma(sf::Vector2f(200.0f, 50.0f), sf::Vector2f(100.0f, 700.0f));
    pColisao->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaObstaculos.inserir(pEntidade);
}
