#pragma once
#include "Estado.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace Estados {

    class GameOver : public Estado {
    private:
        sf::Text BotaoTentarNovamente;
        sf::Text BotaoMenuPrincipal;
        sf::Text BotaoRanking;

        sf::Text textoNome;
        std::string nomeJogador;
        bool inserindoNome;

    public:
        GameOver();
        ~GameOver();
        void PrimeiroExecutar();
        void executar();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
    };
}