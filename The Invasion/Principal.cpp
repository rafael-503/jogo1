#include "stdafx.h"
#include "Principal.h"
#include <iostream>
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"

#define FONTE "assets/fontes/Black Future.OTF"


using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

#include "Estados/MenuPrincipal.h"

//Gerenciadores::GerenciadorGrafico* Principal::pGrafico = NULL;
Principal::Principal():
    pGrafico(pGrafico->getGerenciadorGrafico()), pGerencia_Colisoes(pGerencia_Colisoes->getGerenciador_Colisoes()),
    pGerenciaEventos(pGerenciaEventos->getGerenciadorEvento()), pEstados(pEstados->getGerenciadorEstado())
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

    TESTE DE TEXTOS
    sf::Font blackFuture;
    blackFuture.loadFromFile(FONTE);

    sf::Text teste("TESTE", blackFuture, 10);
    teste.setOrigin(0.0f, 0.0f);
    teste.scale(sf::Vector2f(20.0f, 20.0f));
    teste.setFillColor(sf::Color::White);


*/


    while (pGrafico->verificarJanelaAberta())
    {
        pGerenciaEventos->verificarEventos();
        pGrafico->limparJanela();
        pGrafico->atalizaFundo();

        pEstados->executarEstadoAtual();
        //fase.executar();

        sf::Time tempo_por_frame = sf::seconds(1.0f / 60.0f); // limita a atualização a 60 fps
        sf::sleep(tempo_por_frame);
        pGrafico->mostrarElementos();
    }
}
