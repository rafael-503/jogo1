#pragma once
#include "../stdafx.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Personagens/Jogador.h"
#include <SFML/Graphics.hpp>


using namespace Entidades;

namespace Gerenciadores {

    class Gerenciador_Colisoes {
    private:
        Gerenciador_Colisoes* pGerenciador_Colisoes;
        vector<Personagens::Inimigo*> vetor_inimigos;
        vector<Obstaculos::Obstaculo*> vetor_obstaculos;
    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();
        void incluiInimigo(Personagens::Inimigo* pInimigo);
        void incluiObstaculo(Obstaculos::Obstaculo* pObs);
        void testa_colisoes(Personagens::Jogador* pJogador);
        sf::Vector2f Calcula_colisao(Entidade* pEnti1, Entidade* pEnti2);
        Gerenciador_Colisoes* getGerenciador_Colisoes();
    };








}


