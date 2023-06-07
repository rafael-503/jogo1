#pragma once
#define SOLDADO "The invasion/assets/inimigo/soldado/soldado.png"
#include "Inimigo.h"

namespace Fases{
    class Fase;
}

namespace Entidades {

    namespace Personagens {

        class Soldado : public Inimigo {
        private:
            int dano;
            Fases::Fase* pFase;
            float raioTiroMAX;
            float raioTiroMIN;
            sf::Clock relogioAtirar;

        public:
            Soldado(sf::Vector2f pos, Fases::Fase* pFaseAux = NULL, sf::Vector2f tam_corpo = sf::Vector2f(80.0f, 80.0f));
            ~Soldado();
            void Afastar_se();
            void Atirar();
            void executar();
            void setFase(Fases::Fase* pFaseAux);
            void danar(Jogador* pJog);
            void salvar();

        };
    }
}
