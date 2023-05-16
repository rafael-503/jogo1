#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"
#include <time.h>

#define RAIO_PERSEG_X 150.0f
#define RAIO_PERSEG_Y 150.0f

namespace Entidades {
    namespace Personagens {

        class Jogador;
        class Inimigo : public Personagem {

        private:
            Jogador* jogador;
            sf::Clock relogio;
            sf::Vector2f pos_inicial;
            sf::Vector2f vel;
            short move_aleatorio;

        public:
            Inimigo(sf::Vector2f tam_corpo);
            ~Inimigo();
            void setJogador(Jogador* aux_jogador);
            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posInim);
            void moveAleatorio();
            void executar();
            void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x);

        };
    }
}
