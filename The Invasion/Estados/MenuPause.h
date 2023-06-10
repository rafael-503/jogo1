#pragma once
#include "Menu.h"

namespace Estados{

    class MenuPause: public Menu {
        private:
            sf::Text Botaovoltar;
            sf::Text BotaoSalvar;

        public:
            MenuPause();
            ~MenuPause();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void PrimeiroExecutar();
            void executar();
    };
}