#pragma once
#include "Estado.h"


namespace Estados{

    class MenuPause: public Estado{
        private:
            sf::Text Botaovoltar;

        public:
            MenuPause();
            ~MenuPause();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void PrimeiroExecutar();
            void executar();
    };

}
