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
            void executar();
            void obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X);
            void obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X);
            void obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X);
            void ColidirPlataforma(Entidade* pEnti, sf::Vector2f DistExtremidades, bool colidiu_X);
        };
    }
}
