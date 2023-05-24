#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"
using namespace Entidades;

namespace Listas{

    class ListaEntidades{
        private:
            Lista<Entidade> LEs;
        public:
            ListaEntidades();
            ~ListaEntidades();
            int getSize() const;
            void inserir(Entidade* pE);
            void percorrer();
            void executar();
			void seDesenhe();
            void esvaziar();

    };
}



