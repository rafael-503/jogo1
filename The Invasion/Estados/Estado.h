#pragma once
#include "../Ente.h"

namespace Estados{

    class Estado: public Ente{
        protected:
        public:
            Estado();
            virtual ~Estado();
            virtual void TeclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void PrimeiroExecutar() = 0;
            virtual void executar() = 0;

    };


}
