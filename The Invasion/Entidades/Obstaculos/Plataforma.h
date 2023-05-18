#pragma once
#define CAMINHO "The Invasion/assets/obstaculos/plataformas/plataforma1.png"
#include "Obstaculo.h"

namespace Entidades {

    namespace Obstaculos {

        class Plataforma: public Obstaculo{
        public:
			Plataforma(sf::Vector2f pos);
			~Plataforma();
            void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x);
            void executar();
        };
    }
}