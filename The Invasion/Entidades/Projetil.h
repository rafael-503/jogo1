#pragma once
#include "../stdafx.h"
#include "Entidade.h"
#include "SFML/Graphics.hpp"
#include "Personagens/Jogador.h"
#define PROJETIL "The invasion/assets/inimigo/soldado/projetil.png"

namespace Entidades{

    class Projetil: public Entidade{
        private:
            float vel_projetil;
            Personagens::Jogador* pPerseguido;

        public:
            Projetil(sf::Vector2f posInimigo, Personagens::Jogador* pJogador1 = NULL, Personagens::Jogador* pJogador2 = NULL);
            ~Projetil();
            void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            void danar(Personagens::Jogador* jogador);
            void executar();
    };
}
