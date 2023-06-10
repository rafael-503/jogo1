#pragma once
#include "Menu.h"

namespace Estados {
    class GameOver : public Menu {
    private:
        sf::Text BotaoTentarNovamente;
        sf::Text BotaoMenuPrincipal;
        sf::Text BotaoRanking;

    public:
        GameOver();
        ~GameOver();
        void PrimeiroExecutar();
        void executar();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
    };
}