#pragma once
#include "../Entidade.h"
#include "../Personagens/Jogador.h"

namespace Entidades {

    namespace Obstaculos {

        class Obstaculo : public Entidade {
        protected:

        public:
            Obstaculo(sf::Vector2f pos, sf::Vector2f tam_corpo);
            ~Obstaculo();
            virtual void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
            virtual void executar();
            virtual void obstar(Entidades::Personagens::Jogador* pJog) = 0;
        };
    }
}
