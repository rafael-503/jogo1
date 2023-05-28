#pragma once
#include "Estado.h"


namespace Estados{

    class MenuPause: public Estado{
        private:
            sf::Font fonte;
            sf::Text Botaovoltar;
            Gerenciadores::GerenciadorGrafico* pGrafico;

        public:
            MenuPause();
            ~MenuPause();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void PrimeiroExecutar();
            void executar();
    };

}
