#pragma once
#include "../Ente.h"

namespace Estados{

    class Estado: public Ente{
        public:
            Estado();
            virtual ~Estado();
            virtual void executar() = 0;

    };


}
