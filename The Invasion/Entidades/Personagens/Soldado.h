#pragma once
#define SOLDADO "The invasion/assets/inimigo/soldado/soldado.png"
#include "Inimigo.h"

namespace Entidades {

    namespace Personagens {

        class Soldado : public Inimigo {
        private:
            int dano;
        public:
            Soldado(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(80.0f, 80.0f));
            ~Soldado();
            void danar(Jogador* pJog);
        };
    }
}
