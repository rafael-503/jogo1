#pragma once
#define LENHADOR "The invasion/assets/inimigo/lenhador/lenhador.png"
#include "Inimigo.h"
#include "Jogador.h"

namespace Entidades {
    namespace Personagens {

        class Lenhador : public Inimigo {
        private:
            int forca;
        public:
            Lenhador(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(100.0f, 100.0f));
            ~Lenhador();
            void danar(Jogador* pJog);
            void salvar();

        };
    }
}
