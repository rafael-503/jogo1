#pragma once
#include "Obstaculo.h"
#define CAIXA "The invasion/assets/obstaculos/caixa.png"

namespace Entidades {
	namespace Obstaculos {
		class Caixa : public Obstaculo {
			private:
				float velX;
			public:
				Caixa(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(50.0f, 50.0f));
				~Caixa();
				void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
				void executar();
				void obstar(Entidades::Personagens::Jogador* pJog);
		};
	}
}