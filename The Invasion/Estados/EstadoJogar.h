#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"
#include "../Fases/Fase2.h"

namespace Estados{

    class EstadoJogar: public Estado{
        private:
            Fases::Fase1 fase1;
            Fases::Fase2 fase2;
        public:
            EstadoJogar();
            ~EstadoJogar();
            void PrimeiroExecutar();
            void executar();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void carregarFase2();
    };

}
