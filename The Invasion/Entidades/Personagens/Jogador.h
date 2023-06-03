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
            sf::Vector2f vel_padrao;
            int forca;

        public:
            Jogador(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(80.0f, 80.0f), const char* text= JOGADOR);
            ~Jogador();
            void executar();
            void Mover_Se(bool Direita, bool pulo, float velY = -13.0f);
            void Atacar(Inimigo* pInimigo);
        };
    }
}
