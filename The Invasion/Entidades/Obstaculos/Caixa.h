#pragma once
#include "Obstaculo.h"
#define CAIXA "The invasion/assets/obstaculos/caixa.png"
#define CAIXA2 "The invasion/assets/obstaculos/caixaCuradora.png"

namespace Entidades {
	namespace Obstaculos {
		class Caixa : public Obstaculo {
			private:
				int peso;
			public:
				Caixa(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(50.0f, 50.0f));
				~Caixa();
				void executar();
                void obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X);
                void obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X);
                void obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X);
                void salvar();
                void CarregarSe(string atributos);
        };
	}
}
