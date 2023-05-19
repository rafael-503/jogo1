#pragma once
#include "Obstaculo.h"
#define ESPINHOS "The Invasion/assets/obstaculos/espinhos.png"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo {
		public:
			Espinhos(sf::Vector2f tam_corpo, sf::Vector2f pos);
			~Espinhos();
			void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x);
			void executar();
		};
	}
}