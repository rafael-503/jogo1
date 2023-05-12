#include "stdafx.h"
#include "Principal.h"
#include <iostream>

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

//Gerenciadores::GerenciadorGrafico* Principal::pGrafico = NULL;
Principal::Principal(): pGrafico(pGrafico->getGerenciadorGrafico()){
    if (pGrafico == NULL) {
        std::cout << "Erro ao criar o gerenciador gráfico" << std::endl;
        exit(1);
    }
    executar();
}

Principal::~Principal(){}

void Principal::executar(){


    Gerenciadores::Gerenciador_Colisoes Gerenciador_Colisoes;

    Inimigo inimigo(sf::Vector2f(40.0f, 40.0f));
    Jogador jogador(sf::Vector2f(40.0f, 40.0f));
    Obstaculo obstaculo_1(sf::Vector2f(120.0f, 50.0f), 200.0f, 400.0f);
    inimigo.setJogador(&jogador);

    Entidade* pEntidade = NULL;
    Listas::ListaEntidades listaEntidades;
    //Listas::Lista<Entidade> listaEntidades;
    //apenas um jeito de colocar plataformas TEMPORARIO
    Obstaculo* pObstaculo = NULL;
    int tamx = 1200,tamy = 800, pos_x, pos_y,  n_obs = 8;
    for (int i = 1; i <= n_obs; i++){
        pos_x = rand()%(tamx / n_obs);
        pos_y = rand()% tamy;
        pObstaculo = new Obstaculo(sf::Vector2f(80.0f, 30.0f), pos_x * i, pos_y);
        Gerenciador_Colisoes.incluiObstaculo(pObstaculo);
        pEntidade = static_cast<Entidade*> (pObstaculo);
        if(pEntidade){
            listaEntidades.inserir(pEntidade);
        }
    }

    Jogador* pJogador = &jogador;
    Inimigo* pInimigo = &inimigo;
    Gerenciador_Colisoes.incluiInimigo(pInimigo);
    pEntidade = static_cast<Entidade*> (pJogador);
    listaEntidades.inserir(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    listaEntidades.inserir(pEntidade);

    while (pGrafico->verificarJanelaAberta())
    {
        sf::Event event;

        if(pGrafico->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        pGrafico->limparJanela();

        listaEntidades.executarEntidades();
        Gerenciador_Colisoes.testa_colisoes(&jogador);
        listaEntidades.desenharEntidades();

        sf::Time tempo_por_frame = sf::seconds(1.0f / 60.0f); // limita a atualização a 60 fps
        sf::sleep(tempo_por_frame);
        pGrafico->mostrarElementos();
    }
    listaEntidades.esvaziar();
}
