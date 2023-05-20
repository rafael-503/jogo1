#pragma once
#include "../stdafx.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Personagens/Jogador.h"
#include <SFML/Graphics.hpp>
#include <list>
using namespace Entidades;

namespace Gerenciadores {

    class Gerenciador_Colisoes {
    private:
        static Gerenciador_Colisoes* pGerenciador_Colisoes;
        vector<Personagens::Inimigo*> vetor_inimigos;
        list<Obstaculos::Obstaculo*> lista_obstaculos;
        Gerenciador_Colisoes();
    public:
        ~Gerenciador_Colisoes();
        void incluiInimigo(Personagens::Inimigo* pInimigo);
        void incluiObstaculo(Obstaculos::Obstaculo* pObs);
        void testa_colisoes(Personagens::Jogador* pJogador);
        sf::Vector2f Calcula_colisao(Entidade* pEnti1, Entidade* pEnti2);
        Gerenciador_Colisoes* getGerenciador_Colisoes();
    };








}


