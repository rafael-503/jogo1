#pragma once
#define PLATAFORMA "The Invasion/assets/obstaculos/plataforma1.png"
#include "Obstaculo.h"

namespace Entidades {

    namespace Obstaculos {

        class Plataforma: public Obstaculo{
        public:
			Plataforma(sf::Vector2f tam_corpo, sf::Vector2f pos);
			~Plataforma();
            void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            void executar();
        };
    }
}