#pragma once
#include "../stdafx.h"
#include "../Ente.h"
#include <SFML/Graphics.hpp>

namespace Entidades{

    class Entidade: public Ente{
    protected:
        sf::RectangleShape corpo;

    public:
        Entidade(sf::Vector2f tam_corpo);
        ~Entidade();
        sf::RectangleShape getCorpo();
        const sf::Vector2f getPosition() const;
        virtual void executar() = 0;
    };
}
