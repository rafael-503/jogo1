#pragma once
#define LENHADOR "assets/inimigo/lenhador/lenhador.png"
#include "Inimigo.h"
#include "Jogador.h"

namespace Entidades {

    namespace Personagens {

        class Lenhador : public Inimigo {
        public:
            Lenhador(sf::Vector2f tam_corpo, sf::Vector2f pos);
            ~Lenhador();
        };
    }
}
