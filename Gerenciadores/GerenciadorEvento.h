#pragma once
#include "../Entidades/Personagens/Jogador.h"


namespace Gerenciadores {

    class GerenciadorEvento {
        private:
            static GerenciadorGrafico* pGrafico;
            Entidades::Personagens::Jogador* pJogador;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void executar();
            void verificarEventos();
            void setJogador(Entidades::Personagens::Jogador* pJogadorAux);
    };

}


