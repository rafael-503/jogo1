#pragma once
#include "../Entidade.h"

namespace Entidades {

    namespace Obstaculos {

        class Obstaculo : public Entidade {
        protected:
            sf::Vector2f pos;
        public:
            Obstaculo(sf::Vector2f tam_corpo, float pos_x = 0.0f, float pos_y = 0.0f);
            ~Obstaculo();
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades);
            virtual void executar();
        };
    }
}