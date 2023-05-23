#include "Fase1.h"
using namespace Fases;

Fase1::Fase1() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
	//criarPersonagens();
	//criarObstaculos();
}

Fase1::~Fase1() {

}

void Fase1::executar() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
	listaObstaculos.executar();
	listaPersonagens.executar();

	//gerenciarColisoes();
	criarPersonagens();
	//criarObstaculos();

	//listaObstaculos.seDesenhe();
	listaPersonagens.seDesenhe();
}

void Fase1::criarPersonagens() {
	Entidades::Personagens::Cachorro cachorro(sf::Vector2f(80.0f, 80.0f), sf::Vector2f(80.0f, 80.0f));
	Entidades::Personagens::Jogador jogador(sf::Vector2f(80.0f, 80.0f));
	cachorro.setJogador(&jogador);

	listaPersonagens.inserir(&cachorro);
	listaPersonagens.inserir(&jogador);
}


void Fase1::criarObstaculos() {

	Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(200.0f, 50.0f), sf::Vector2f(100.0f, 700.0f));
	//pGerencia_Colisoes->incluiObstaculo(pObstaculo);
	listaObstaculos.inserir(static_cast<Entidade*> (plat));

}