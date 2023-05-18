#pragma once
#include "../Entidade.h"

namespace Entidades {

    namespace Obstaculos {

        class Obstaculo : public Entidade {
        protected:

        public:
            Obstaculo(sf::Vector2f tam_corpo, float pos_x = 0.0f, float pos_y = 0.0f);
            ~Obstaculo();
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x);
            virtual void executar();
        };
    }
}
