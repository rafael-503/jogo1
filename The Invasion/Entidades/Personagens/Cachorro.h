#pragma once
#define CACHORRO "The invasion/assets/inimigo/cachorro/cachorro.png"
#include "Inimigo.h"

namespace Entidades {

    namespace Personagens {

        class Cachorro : public Inimigo {
        public:
            Cachorro(sf::Vector2f tam_corpo, sf::Vector2f pos);
            ~Cachorro();
        };
    }
}
