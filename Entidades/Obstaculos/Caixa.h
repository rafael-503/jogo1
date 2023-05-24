#pragma once
#include "Obstaculo.h"
#define CAIXA "assets/obstaculos/caixa.png"

namespace Entidades {
	namespace Obstaculos {
		class Caixa : public Obstaculo {
			public:
				Caixa(sf::Vector2f tam_corpo, sf::Vector2f pos);
				~Caixa();
				void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
				void executar();
		};
	}
}
