#pragma once
#include "Obstaculo.h"
#define ESPINHOS "The invasion/assets/obstaculos/espinhos.png"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo {
        private:
			int dano;
		public:
			Espinhos(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(50.0f, 50.0f));
			~Espinhos();
			void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
			void executar();
			void obstar(Entidades::Personagens::Jogador* pJog);
		};
	}
}
