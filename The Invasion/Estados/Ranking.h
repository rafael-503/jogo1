#pragma once
#include "Estado.h"

namespace Estados {

    class Ranking : public Estado {
    private:
        sf::Text BotaoMenuPrincipal;

    public:
        Ranking();
        ~Ranking();
        void PrimeiroExecutar();
        void executar();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
    };
}