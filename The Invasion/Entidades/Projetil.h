#pragma once
#include "../stdafx.h"
#include "Entidade.h"
#include "SFML/Graphics.hpp"
#include "Personagens/Jogador.h"

namespace Entidades{

    class Projetil: public Entidade{
        private:
            float vel_projetil;
            Personagens::Jogador* pPerseguido;

        public:
            Projetil(sf::Vector2f posInimigo, Personagens::Jogador* pJogador1 = NULL, Personagens::Jogador* pJogador2 = NULL);
            ~Projetil();
            void executar();
    };

}
