#pragma once
#include "Menu.h"
#include "../Fases/Fase1.h"
#include "../Fases/Fase2.h"

namespace Estados{

    class EstadoJogar: public Menu {
        private:
            Fases::Fase* pFase;
            bool Eh_fase1;
            bool Eh_1_Jogador;
        public:
            EstadoJogar(bool eh_fase1 = true, bool eh_1_jogador = true);
            ~EstadoJogar();
            bool getEh_fase1() const;
            bool getEh_1_Jogador() const;
            void PrimeiroExecutar();
            void executar();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void carregarFase2();
    };

}
