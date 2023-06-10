#pragma once
#include "Fase.h"

namespace Fases {
	class Fase2 : public Fase {
	private:
		const int POS_MIN;
		const int POS_MAX;

	public:
		Fase2(bool AuxEh_1_jogador = true);
		~Fase2();
		void criarPersonagens();
		void criarObstaculos();
        void criarCachorros();
        void criarSoldado();
        void criarLenhadores();
        void criarPlataformas();
        void criarCaixas();
        void criarEspinhos();
		void executar();
		void esvaziar();
	};
}