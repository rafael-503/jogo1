#pragma once
#include "../stdafx.h"
#include "../Estados/Estado.h"
#include "../Estados/MenuPrincipal.h"
#include "../Estados/EstadoJogar.h"
#include "../Fases/Fase1.h"
#include <map>

typedef map< string, Estados::Estado*> MapaStringEstado;

namespace Gerenciadores{

    class GerenciadorEstado{
        private:
            MapaStringEstado mapEstados;
            static GerenciadorEstado* pEstados;
            string EstadoAtual;
            //singleton
            GerenciadorEstado();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executarEstadoAtual();
            void setEstadoAtual(string& estadoAux);
    };

}
