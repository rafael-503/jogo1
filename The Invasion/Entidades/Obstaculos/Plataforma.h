#pragma once
#define PLATAFORMA "The invasion/assets/obstaculos/plataforma1.png"

#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {

        class Plataforma: public Obstaculo{
        private:
            float velY;
        public:
			Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(200.0f, 50.0f), const char* text= PLATAFORMA);
			~Plataforma();
            void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            void executar();
            void obstar(Entidades::Personagens::Jogador* pJog);
        };
    }
}