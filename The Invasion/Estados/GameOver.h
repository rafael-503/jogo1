#pragma once
#include "Estado.h"

namespace Estados {

    class GameOver : public Estado {
    private:
        sf::Text BotaoTentarNovamente;
        sf::Text BotaoMenuPrincipal;

    public:
        GameOver();
        ~GameOver();
        void PrimeiroExecutar();
        void executar();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
    };
}