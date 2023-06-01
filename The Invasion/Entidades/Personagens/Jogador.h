#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"

#define JOGADOR "The invasion/assets/personagem/jogador/personagem.png"

namespace Entidades {

    namespace Personagens {

        class Inimigo;
        class Jogador : public Personagem {
        private:
            void inicializa();
            sf::Clock relogioColisao;

        public:
            Jogador(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(80.0f, 80.0f), const char* text= JOGADOR);
            ~Jogador();
            void executar();
            void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            void move(bool Direita, bool pulo, float velY = -13.0f);
            void atacar(int dano, Inimigo* pInimigo);
        };
    }
}
