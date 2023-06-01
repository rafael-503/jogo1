#pragma once
#define CACHORRO "The invasion/assets/inimigo/cachorro/cachorro.png"
#define CACHORRO2 "The invasion/assets/inimigo/cachorro/cachorro1.png"

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Cachorro : public Inimigo {
        private:
            bool manso;
        public:
            Cachorro(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(70.0f, 70.0f));
            ~Cachorro();
            void danar(Jogador* pJog);
        };
    }
}
