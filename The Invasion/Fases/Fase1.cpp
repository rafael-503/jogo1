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
    //pColisao->testa_colisoes(&jogador);
	listaPersonagens.seDesenhe();
	listaObstaculos.seDesenhe();
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
}

void Fase1::criarPersonagens() {
    Entidades::Personagens::Soldado inimigo(sf::Vector2f(80.0f, 80.0f), sf::Vector2f(80.0f, 80.0f));
    Entidades::Personagens::Jogador jogador(sf::Vector2f(80.0f, 80.0f));
    inimigo.setJogador(&jogador);

    Entidade* pEntidade = NULL;

    Entidades::Personagens::Jogador* pJogador = &jogador;
    Entidades::Personagens::Inimigo* pInimigo = &inimigo;

    pColisao->incluiInimigo(pInimigo);
    pEntidade = static_cast<Entidade*> (pJogador);
    listaPersonagens.inserir(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    listaPersonagens.inserir(pEntidade);

    pEventos->setJogador(pJogador);
    //
    pColisao->testa_colisoes(&jogador);
}

void Fase1::criarObstaculos() {
    Entidade* pEntidade = NULL;
    Entidades::Obstaculos::Obstaculo* pObstaculo = NULL;

    pObstaculo = new Entidades::Obstaculos::Plataforma(sf::Vector2f(200.0f, 50.0f), sf::Vector2f(100.0f, 700.0f));
    pColisao->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaObstaculos.inserir(pEntidade);
}