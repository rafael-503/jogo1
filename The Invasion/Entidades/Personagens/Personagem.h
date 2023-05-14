#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "../Entidade.h"

namespace Entidades {
    namespace Personagens {

        class Personagem : public Entidade {
        protected:

        public:
            Personagem(sf::Vector2f tam_corpo, string tipo);
            ~Personagem();
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades) = 0;
            virtual void executar() = 0;
        };
    }
}