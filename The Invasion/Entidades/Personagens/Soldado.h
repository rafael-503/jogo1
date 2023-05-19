#pragma once
#define SOLDADO "The Invasion/assets/inimigo/soldado/soldado.png"
#include "Inimigo.h"

namespace Entidades {

    namespace Personagens {

        class Soldado : public Inimigo {
        public:
            Soldado(sf::Vector2f tam_corpo, sf::Vector2f pos);
            ~Soldado();
        };
    }
}