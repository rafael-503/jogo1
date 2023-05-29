#pragma once
#include "Estado.h"

namespace Estados {

    class Ranking : public Estado {
    private:
        sf::Text BotaoMenuPrincipal;
        vector<sf::Text*> vectorPontuacoes;

        sf::Text textoNome;
        std::string nomeJogador;
        bool inserindoNome;

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