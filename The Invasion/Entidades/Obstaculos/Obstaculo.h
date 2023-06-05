#pragma once
#include "../Entidade.h"
#include "../Personagens/Jogador.h"

namespace Entidades {

    namespace Obstaculos {

        class Obstaculo : public Entidade {
        protected:
            sf::Clock relogioDanoso;
        public:
            Obstaculo(sf::Vector2f pos, sf::Vector2f tam_corpo);
            ~Obstaculo();
            virtual void executar();
            virtual void obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X) = 0;
            virtual void obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X) = 0;
            virtual void obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X) = 0;
        };
    }
}
