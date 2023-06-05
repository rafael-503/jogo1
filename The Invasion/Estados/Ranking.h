#pragma once
#include "Menu.h"

typedef std::multimap<int, sf::Text*, std::greater<int> > MultiMapaIntText;

namespace Estados {

    class Ranking : public Menu {
    private:
        sf::Text BotaoMenuPrincipal;
        vector<sf::Text*> vectorPontuacoes;
        MultiMapaIntText MapPontuacoes;

    public:
        Ranking();
        ~Ranking();
        void PrimeiroExecutar();
        void executar();
        void salvarRanking();
        void carregarRanking();
        void TeclaPressionada(const sf::Keyboard::Key tecla);
        void guardarPontuacao(int num);
        void imprimirPontuacao();
        void SalvarTextoPontuacao(sf::Text* pTexto, int pontuacao);
    };
}
