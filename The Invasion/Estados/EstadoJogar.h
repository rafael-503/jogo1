#pragma once
#include "Menu.h"
#include "../Fases/Fase1.h"
#include "../Fases/Fase2.h"

namespace Estados{

    class EstadoJogar: public Menu {
        private:
            Fases::Fase* pFase;
            //Fases::Fase1 fase1;
            //Fases::Fase2 fase2;

        public:
            EstadoJogar(bool eh_fase1 = true, bool eh_1_jogador = true);
            ~EstadoJogar();
            void PrimeiroExecutar();
            void executar();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void carregarFase2();
    };

}
