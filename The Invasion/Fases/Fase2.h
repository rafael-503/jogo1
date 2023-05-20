#pragma once
#include "Fase.h"

namespace Fases {
	class Fase2 : public Fase {
	public:
		Fase2();
		~Fase2();
		void criarInimigos();
		void criarObstaculos();
	};
}
