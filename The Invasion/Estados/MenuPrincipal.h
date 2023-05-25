#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"

namespace Estados{

    class MenuPrincipal: public Estado{
        private:
        Fases::Fase1 fase1;
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void executar();

    };


}

