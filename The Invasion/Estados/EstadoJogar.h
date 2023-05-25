#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"

namespace Estados{

    class EstadoJogar: public Estado{
        private:
            Fases::Fase1 fase1;
        public:
            EstadoJogar();
            ~EstadoJogar();
            void executar();

    };

}
