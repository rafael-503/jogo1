#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "../Entidade.h"

namespace Entidades {
    namespace Personagens {

        class Personagem : public Entidade {
        protected:
            bool colidiu_em_y;
            float massa;
        public:
            Personagem(sf::Vector2f tam_corpo, string tipo);
            ~Personagem();
            void setMassa(float massa_aux);
            float getMassa();
            void efeitoGravidade();
            void setVelocidade(sf::Vector2f velocidade);
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) = 0;
            virtual void executar() = 0;
        };
    }
}
