#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "../Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Personagem : public Entidade {
        private:
            int vida;
            
        public:
            Personagem(sf::Vector2f tam_corpo);
            ~Personagem();
            int getVida() const;
            void setVida(int vida);
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) = 0;
            virtual void executar() = 0;
            void atacar();
        };
    }
}
