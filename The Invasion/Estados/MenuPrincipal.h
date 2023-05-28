#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"


namespace Estados{

    class MenuPrincipal: public Estado{
        private:
            sf::Text BotaoJogar;
            sf::Text BotaoRanking;
            sf::Text BotaoSair;
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void PrimeiroExecutar();
            void executar();
            void TeclaPressionada(const sf::Keyboard::Key tecla);

    };


}

