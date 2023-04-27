#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"

class Principal{
    private:
        sf::RenderWindow* janela;
        Personagem personagem;
    public:
        Principal();
        ~Principal();
        void executar();
};