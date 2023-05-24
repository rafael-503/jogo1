#pragma once
#include "../stdafx.h"
#include "Entidade.h"
#include "SFML/Graphics.hpp"

namespace Entidades{

    class Projetil: public Entidade{
        private:
        public:
            Projetil(sf::Vector2f tam_corpo, sf::Vector2f pos_inicial);
            ~Projetil();
    };

}
