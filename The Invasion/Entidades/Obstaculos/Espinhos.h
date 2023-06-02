#pragma once
#include "Obstaculo.h"
#define ESPINHOS "The invasion/assets/obstaculos/espinhos.png"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo {
        private:
			int dano;
			sf::Clock RelogioEspinho;
		public:
			Espinhos(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(50.0f, 50.0f));
			~Espinhos();
			void executar();
			void obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X);
			void obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X);
            void obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X);
		};
	}
}
