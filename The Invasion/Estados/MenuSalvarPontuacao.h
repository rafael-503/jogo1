#pragma once
#include "Menu.h"
#include "Ranking.h"

namespace Estados{

    class MenuSalvarPontuacao: public Menu {
        private:
            Ranking* pRanking;
            sf::Text TextoParabens;
            sf::Text TextoInstrucoes;
            sf::Text TextoPontuacao;
            sf::Text TextoNome;
            int UltimaPontuacao;
            char UltimaLetra;

        public:
            MenuSalvarPontuacao(Ranking* pRankingAux = NULL);
            ~MenuSalvarPontuacao();
            void TeclaPressionada(const sf::Keyboard::Key tecla);
            void AdicionarPontuacao(int pontuacao);
            void PrimeiroExecutar();
            void executar();
    };
}