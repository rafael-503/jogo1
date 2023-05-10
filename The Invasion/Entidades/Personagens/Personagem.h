#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "../Entidade.h"

namespace Entidades{
    namespace Personagens{

        class Personagem: public Entidade{
        protected:
            
        public:
            Personagem(sf::Vector2f tam_corpo);
            ~Personagem();
            virtual void executar() = 0;
        };
    }
}