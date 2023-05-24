#include "stdafx.h"
#include "Principal.h"
#include <iostream>
#include "Listas/Lista.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Obstaculos/Espinhos.h"
#include "Entidades/Obstaculos/Caixa.h"
#include "Entidades/Personagens/Cachorro.h"
#include "Entidades/Personagens/Lenhador.h"
#include "Entidades/Personagens/Soldado.h"
#include "Fases/Fase1.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

//Gerenciadores::GerenciadorGrafico* Principal::pGrafico = NULL;
Principal::Principal():
    pGrafico(pGrafico->getGerenciadorGrafico()), pGerencia_Colisoes(pGerencia_Colisoes->getGerenciador_Colisoes()),
    pGerenciaEventos(pGerenciaEventos->getGerenciadorEvento())
{
    if (pGrafico == NULL) {
        std::cout << "Erro ao criar o gerenciador gráfico" << std::endl;
        exit(1);
    }
    executar();
}

Principal::~Principal(){}

void Principal::executar(){
    /*
    Soldado inimigo(sf::Vector2f(80.0f, 80.0f), sf::Vector2f(80.0f, 80.0f));
    Jogador jogador(sf::Vector2f(80.0f, 80.0f));
    inimigo.setJogador(&jogador);

    Entidade* pEntidade = NULL;
    Obstaculo* pObstaculo = NULL;
    Listas::ListaEntidades listaPersonagens;
    Listas::ListaEntidades listaObstaculos;

    Jogador* pJogador = &jogador;
    Inimigo* pInimigo = &inimigo;

    pGerencia_Colisoes->incluiInimigo(pInimigo);
    pEntidade = static_cast<Entidade*> (pJogador);
    listaPersonagens.inserir(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    listaPersonagens.inserir(pEntidade);


    pObstaculo = new Plataforma(sf::Vector2f(200.0f, 50.0f), sf::Vector2f(100.0f, 700.0f));
    pGerencia_Colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaObstaculos.inserir(pEntidade);

    pGerenciaEventos->setJogador(pJogador);
    */
    Fases::Fase1 fase1;
    fase1.criarObstaculos();
    fase1.criarPersonagens();

    while (pGrafico->verificarJanelaAberta())
    {
        pGerenciaEventos->verificarEventos();
        pGrafico->limparJanela();

        fase1.executar();
        //listaPersonagens.executar();
        //listaObstaculos.executar();
        //pGerencia_Colisoes->testa_colisoes(&jogador);

        //listaPersonagens.seDesenhe();
        //listaObstaculos.seDesenhe();


        sf::Time tempo_por_frame = sf::seconds(1.0f / 60.0f); // limita a atualização a 60 fps
        sf::sleep(tempo_por_frame);
        pGrafico->mostrarElementos();
    }
    fase1.esvaziar();
    //listaPersonagens.esvaziar();
    //listaObstaculos.esvaziar();
}
