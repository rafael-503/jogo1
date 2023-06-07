#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
using namespace Entidades;

namespace Fases{
    class Fase;

}

namespace Listas{

    class ListaEntidades{
        private:
            Lista<Entidade> LEs;
        public:
            ListaEntidades();
            ~ListaEntidades();
            int getSize() const;
            void inserir(Entidade* pE);
            void remover(Entidade* pE);
            void percorrer();
            void executar();
			void seDesenhe();
            void esvaziar();
            void verificarVida(Gerenciadores::Gerenciador_Colisoes* pColisao);
            void apagarElemento(Entidades::Entidade* pEnti, Gerenciadores::Gerenciador_Colisoes* pColisao);
            void GravarSe(ofstream* pArquivo);
            void SalvarEntidades();
    };
}



