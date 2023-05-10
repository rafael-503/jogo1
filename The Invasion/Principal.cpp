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
    Inimigo inimigo(sf::Vector2f(40.0f, 40.0f));
    Jogador jogador(sf::Vector2f(40.0f, 40.0f));
    Obstaculo obstaculo_1(sf::Vector2f(120.0f, 50.0f), 200.0f, 400.0f);
    inimigo.setJogador(&jogador);

    Entidade* pEntidade = NULL;
    std::vector<Entidade*> vet_entidades;

    //apenas um jeito de colocar plataformas TEMPORARIO
    Obstaculo* pObstaculo = NULL;
    int tamx = 1200,tamy = 800, pos_x, pos_y,  n_obs = 8;
    for (int i = 1; i <= n_obs; i++){
        pos_x = rand()%(tamx / n_obs);
        pos_y = rand()% tamy;
        pObstaculo = new Obstaculo(sf::Vector2f(80.0f, 30.0f), pos_x * i, pos_y);
        pEntidade = static_cast<Entidade*> (pObstaculo);
        if(pEntidade)
            vet_entidades.push_back(pEntidade);
    }

    Jogador* pJogador = &jogador;
    Inimigo* pInimigo = &inimigo;
    pEntidade = static_cast<Entidade*> (pJogador);
    vet_entidades.push_back(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    vet_entidades.push_back(pEntidade);

    while (pGrafico->verificarJanelaAberta())
    {
        sf::Event event;

        if(pGrafico->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        pGrafico->limparJanela();
        for (int i = 0; i < (int)vet_entidades.size(); i++) {
            vet_entidades[i]->executar();
            pGrafico->desenharElemento(vet_entidades[i]->getCorpo());
        }
        sf::Time tempo_por_frame = sf::seconds(1.0f / 60.0f); // limita a atualização a 60 fps
        sf::sleep(tempo_por_frame);
        pGrafico->mostrarElementos();
    }
    vet_entidades.clear();
}