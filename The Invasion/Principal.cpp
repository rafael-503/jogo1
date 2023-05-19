#include "stdafx.h"
#include "Principal.h"
#include <iostream>
#include "Listas/Lista.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Obstaculos/Espinhos.h"
#include "Entidades/Obstaculos/Caixa.h"

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

   // ListaEntidades lista;


    Gerenciadores::Gerenciador_Colisoes* pGerencia_colisoes(pGerencia_Colisoes->getGerenciador_Colisoes());

    Inimigo inimigo(sf::Vector2f(80.0f, 80.0f));
    Jogador jogador(sf::Vector2f(80.0f, 80.0f));
    inimigo.setJogador(&jogador);

    Entidade* pEntidade = NULL;
    Listas::ListaEntidades listaEntidades;

    Obstaculo* pObstaculo = NULL;

    Jogador* pJogador = &jogador;
    Inimigo* pInimigo = &inimigo;



    pGerencia_colisoes->incluiInimigo(pInimigo);
    pEntidade = static_cast<Entidade*> (pJogador);
    listaEntidades.inserir(pEntidade);
    pEntidade = static_cast<Entidade*> (pInimigo);
    listaEntidades.inserir(pEntidade);


    pObstaculo = new Plataforma(sf::Vector2f(200.0f, 50.0f), sf::Vector2f(100.0f, 700.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    pObstaculo = new Espinhos(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(700.0f, 400.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    pObstaculo = new Caixa(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(750.0f, 450.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    pObstaculo = new Plataforma(sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 600.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    pObstaculo = new Plataforma(sf::Vector2f(180.0f, 50.0f), sf::Vector2f(500.0f, 500.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);
    /*
    pObstaculo = new Plataforma(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(700.0f, 400.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);
    */
    pObstaculo = new Plataforma(sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 350.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    pObstaculo = new Plataforma(sf::Vector2f(180.0f, 50.0f), sf::Vector2f(800.0f, 600.0f));
    pGerencia_colisoes->incluiObstaculo(pObstaculo);
    pEntidade = static_cast<Entidade*> (pObstaculo);
    listaEntidades.inserir(pEntidade);

    /// Fundo temporario
    sf::Texture texture;
    if (!texture.loadFromFile("The invasion/assets/fundo/fundo1.png"))
        std::cout << "Erro ao carregar a textura" << std::endl;

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    sf::Vector2u windowSize = pGrafico->getWindow()->getSize();
    sprite.setScale(
        static_cast<float>(windowSize.x) / sprite.getTexture()->getSize().x,
        static_cast<float>(windowSize.y) / sprite.getTexture()->getSize().y
    );
    ///

    while (pGrafico->verificarJanelaAberta())
    {
        sf::Event event;

        if(pGrafico->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        pGrafico->limparJanela();
        pGrafico->getWindow()->draw(sprite); // fundo

        listaEntidades.executar();
        pGerencia_colisoes->testa_colisoes(&jogador);
        listaEntidades.seDesenhe();
       // pGrafico->desenharElemento(pAux->getCorpo());

        sf::Time tempo_por_frame = sf::seconds(1.0f / 60.0f); // limita a atualização a 60 fps
        sf::sleep(tempo_por_frame);
        pGrafico->mostrarElementos();
    }
    listaEntidades.esvaziar();
}
