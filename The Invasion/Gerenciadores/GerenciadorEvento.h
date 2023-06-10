#pragma once
#include "GerenciadorGrafico.h"

namespace Gerenciadores {

    class GerenciadorEstado;
    class GerenciadorEvento {
        private:
            //padrão de projeto singleton
            static GerenciadorGrafico* pGrafico;
            GerenciadorEstado* pGEstado;
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();

        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void executar();
            void verificarEventos();
    };
}