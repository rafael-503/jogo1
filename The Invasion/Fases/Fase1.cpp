#include "Fase1.h"
using namespace Fases;
#define JOGADOR2 "The invasion/assets/personagem/jogador/personagem2.png"

Fase1::Fase1(bool AuxEh_1_jogador): POS_MIN(1000), POS_MAX(2500) {
    eh_1_jogador = AuxEh_1_jogador;
	if(pGrafico)
        pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
    else
        cout << "pGrafico Nulo na construtora da fase 1" << endl;
	criarPersonagens();
	criarObstaculos();
}

Fase1::~Fase1() {
    pColisao->limpar();
    pColisao = NULL;
    pJogador1 = NULL;
    esvaziar();
    cout << "Fase 1 destruida" << endl;
}

void Fase1::executar() {
	listaPersonagens.executar();
	listaObstaculos.executar();
	listaMisseis.executar();
    pColisao->testa_colisoes();
	listaPersonagens.seDesenhe();
    listaObstaculos.seDesenhe();
    listaMisseis.seDesenhe();
    if(eh_1_jogador)
        pGrafico->mostrarVidaJogador(pJogador1->getVida(), 0, eh_1_jogador);
    else
        pGrafico->mostrarVidaJogador(pJogador1->getVida(), pJogador2->getVida(), eh_1_jogador);
    listaPersonagens.verificarVida(pColisao);
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
	listaMisseis.esvaziar();
}

void Fase1::criarPersonagens() {
    criarJogadores();
    criarSoldado();
    criarLenhadores();
    criarCachorros();
}

void Fase1::criarObstaculos() {
    criarPlataformas();
    criarCaixas();
}

void Fase1::criarCachorros(){
    construtorPersonagens("Cachorro", sf::Vector2f(800.0f, 200.0f));

    // Criacao de inimigos aleatorios
    srand(time(0));
    int numInimigos = rand() % 7 + 3; // Gera numeros entre 3 e 11
    int x = POS_MIN + (rand() % (POS_MAX - POS_MIN + 1)); // Gera numeros entre 500 e 2000
    int diferenca = (POS_MAX - POS_MIN) / (numInimigos - 1); // Diferenca entre as posicoes dos inimigos

    for (int i = 0; i < numInimigos; i++) {
        int posicaoX = x + (diferenca * i);
        construtorPersonagens("Cachorro", sf::Vector2f(posicaoX, 0.0f));
    }
}

void Fase1::criarSoldado(){
    construtorPersonagens("Soldado", sf::Vector2f(3300.0f, 0.0f));
}

void Fase1::criarLenhadores(){
    construtorPersonagens("Lenhador", sf::Vector2f(800.0f, 200.0f));

    // Criacao de inimigos aleatorios
    srand(time(0));
    int numInimigos = rand() % 3 + 3; // Gera numeros entre 3 e 6
    int x = POS_MIN + (rand() % (POS_MAX - POS_MIN + 1)); // Gera numeros entre 500 e 2000
    int diferenca = (POS_MAX - POS_MIN) / (numInimigos - 1); // Diferenca entre as posicoes dos inimigos

    for (int i = 0; i < numInimigos; i++) {
        int posicaoX = x + (diferenca * i);
        construtorPersonagens("Lenhador", sf::Vector2f(posicaoX, 0.0f));
    }
}

void Fase1::criarPlataformas(){
    construtorObstaculos("Plataforma", sf::Vector2f(0.0f, 800.0f), sf::Vector2f(25000.0f, 50.0f)); // remover

    construtorObstaculos("Plataforma", sf::Vector2f(0.0f, 750.0f), sf::Vector2f(180.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(300.0f, 600.0f), sf::Vector2f(180.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(500.0f, 500.0f), sf::Vector2f(180.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(300.0f, 350.0f), sf::Vector2f(230.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(780.0f, 200.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(780.0f, 600.0f), sf::Vector2f(230.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(1000.0f, 600.0f), sf::Vector2f(230.0f, 50.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(1300.0f, 150.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(1500.0f, 150.0f));

    construtorObstaculos("Plataforma", sf::Vector2f(1700.0f, 700.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(2080.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(2260.0f, 500.0f));

    construtorObstaculos("Plataforma", sf::Vector2f(3000.0f, 600.0f), sf::Vector2f(700.0f, 50.0f)); // soldado
    construtorObstaculos("Plataforma", sf::Vector2f(2805.0f, 560.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(3695.0f, 560.0f));

    // Criacao de obstaculos aleatorios
    srand(time(0));

    int numObstaculos = rand() % 5 + 3; // Gera numeros entre 3 e 7
    for (int i = 1; i < +numObstaculos; i++) {
        int x = 1000 + (rand() % (2500 - 1000 + 1));
        int y = 0 + (rand() % (750 - 0 + 1));
        construtorObstaculos("Plataforma", sf::Vector2f(x - 20 * i, y * i));
    }
}

void Fase1::criarCaixas(){
    construtorObstaculos("Caixa", sf::Vector2f(330.0f, 0.0f));

    // Criacao de obstaculos aleatorios
    srand(time(0));

    int numObstaculos = rand() % 5 + 3; // Gera numeros entre 3 e 7
    for (int i = 1; i < +numObstaculos; i++) {
        int x = 1000 + (rand() % (2500 - 1000 + 1));
        int y = 0 + (rand() % (750 - 0 + 1));
        construtorObstaculos("Caixa", sf::Vector2f(x + 100 * i, 0.0f));
    }
}