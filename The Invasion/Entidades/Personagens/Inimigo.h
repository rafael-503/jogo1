#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"
#include "Jogador.h"
#include <time.h>

#define RAIO_PERSEG_X 300.0f
#define RAIO_PERSEG_Y 300.0f

namespace Entidades {
    namespace Personagens {

        class Jogador;
        class Inimigo : public Personagem {

        protected:
            Jogador* jogador;
            short move_aleatorio;
            sf::Clock relogioColisao;
            sf::Clock relogioAtaque;

        public:
            Inimigo(sf::Vector2f tam_corpo);
            ~Inimigo();
            void setJogador(Jogador* aux_jogador);
            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posInim);
            void moveAleatorio();
            void executar();
            virtual void danar(Jogador* pJog) = 0;
        };
    }
}
