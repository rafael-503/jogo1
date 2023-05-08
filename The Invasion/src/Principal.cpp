#include "stdafx.h"
#include "Principal.h"
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Principal::Principal(){
    executar();
}

Principal::~Principal(){}

void Principal::executar(){


    Inimigo inimigo(sf::Vector2f(40.0f, 40.0f));
    Jogador jogador(sf::Vector2f(40.0f, 40.0f));
    Obstaculo obstaculo_1(sf::Vector2f(120.0f, 50.0f), 200.0f, 400.0f);
    inimigo.setJogador(&jogador);
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Jogo");


    Entidade* pEntidade = NULL;
    std::vector<Entidade*> vet_entidades;


    //apenas um jeito de colocar plataformas TEMPORARIO
    Obstaculo* pObstaculo = NULL;
    int tamx = 1200,tamy = 600, pos_x, pos_y,  n_obs = 8;
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


    while (window.isOpen())
    {

        sf::Event event;

        if(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed){
                for(int i = 0; i < (int) vet_entidades.size(); i++)
                    vet_entidades[i]->executar();
            }
        }

        window.clear();
        for(int i = 0; i < (int) vet_entidades.size(); i++)
            window.draw(vet_entidades[i]->getCorpo());
        window.display();
    }
}





