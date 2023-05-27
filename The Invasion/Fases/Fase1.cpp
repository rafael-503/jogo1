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
    if(pJogador)
        pGrafico->mostrarVidaJogador(pJogador->getVida());
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
}

void Fase1::construtorObstaculos(const std::string& tipo, const sf::Vector2f& tam, const sf::Vector2f& pos) {
    Entidades::Obstaculos::Obstaculo* pObstaculo = NULL;
    Entidade* pEntidade = NULL;

    if (tipo == "Caixa")
        pObstaculo = new Entidades::Obstaculos::Caixa(tam, pos);
    else if (tipo == "Espinhos")
        pObstaculo = new Entidades::Obstaculos::Espinhos(tam, pos);
    else if (tipo == "Plataforma")
        pObstaculo = new Entidades::Obstaculos::Plataforma(tam, pos);
    else {
        cout << "Erro: Tipo de obstaculo invalido" << endl;
        return;
    }
        
    if (pObstaculo) {
        pColisao->incluiObstaculo(pObstaculo);
        pEntidade = static_cast<Entidade*>(pObstaculo);
        listaObstaculos.inserir(pEntidade);
    }
}

void Fase1::construtorPersonagens(const std::string& tipo, Entidades::Personagens::Jogador* pJogador, const sf::Vector2f& tam, const sf::Vector2f& pos) {
    Entidades::Entidade* pEntidade = NULL;
	Entidades::Personagens::Inimigo* pInimigo = NULL;

    if (tipo == "Cachorro") {
    	Entidades::Personagens::Cachorro* pCachorro = new Entidades::Personagens::Cachorro(tam, pos);
		pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pCachorro);
    }
    else if (tipo == "Soldado") {
        Entidades::Personagens::Soldado* pSoldado = new Entidades::Personagens::Soldado(tam, pos);
        pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pSoldado);
    }
    else if (tipo == "Lenhador") {
        Entidades::Personagens::Lenhador* pLenhador = new Entidades::Personagens::Lenhador(tam, pos);
		pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pLenhador);
    }
    else {
		cout << "Erro: Tipo de personagem invalido" << endl;
		return;
	}

    if (pInimigo) {
        pInimigo->setJogador(pJogador);
		pColisao->incluiInimigo(pInimigo);
		pEntidade = static_cast<Entidade*>(pInimigo);
		listaPersonagens.inserir(pEntidade);
	}
}

void Fase1::criarPersonagens() {
    Entidades::Entidade* pEntidade = NULL;
    Entidades::Personagens::Jogador* pJogador = new Entidades::Personagens::Jogador(sf::Vector2f(80.0f, 80.0f), sf::Vector2f(10.0f, 0.0f));
    this->pJogador = pJogador;

    pEntidade = static_cast<Entidade*> (pJogador);

    listaPersonagens.inserir(pEntidade);

    pEventos->setJogador(pJogador);
    pColisao->setJogador(pJogador);
    
    construtorPersonagens("Soldado", pJogador, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(800.0f, 200.0f));
}

void Fase1::criarObstaculos() {
    construtorObstaculos("Caixa", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(330.0f, 0.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(250.0f, 50.0f), sf::Vector2f(0.0f, 750.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(500.0f, 500.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 350.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(780.0f, 200.0f));
    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(780.0f, 165.0f));
    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(810.0f, 165.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(780.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(1000.0f, 600.0f));

}