#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"

namespace Entidades{

    namespace Personagens{

        class Jogador;
        class Inimigo: public Personagem{

        private:
            Jogador* jogador;
            sf::Vector2f pos_inicial;
            sf::Vector2f vel;

        public:
            Inimigo(sf::Vector2f tam_corpo);
            ~Inimigo();
            void executar();
            void setJogador(Jogador* aux_jogador);

        };
    }
}
