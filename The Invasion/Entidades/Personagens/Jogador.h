#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"

namespace Entidades {

    namespace Personagens {

        class Jogador : public Personagem {

        private:
            void inicializa();

        public:
            Jogador(sf::Vector2f tam_corpo);
            ~Jogador();
            void executar();
            void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            void move(bool Direita, bool pulo);
        };
    }
}