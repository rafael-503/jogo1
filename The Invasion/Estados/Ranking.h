#pragma once
#include "Menu.h"

namespace Estados {

    class Ranking : public Menu {
    private:
        sf::Text BotaoMenuPrincipal;
        vector<sf::Text*> vectorPontuacoes;

    public:
        Ranking();
        ~Ranking();
        void PrimeiroExecutar();
        void executar();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
        void guardarPontuacao(int num);
        void imprimirPontuacao();
    };
}