#pragma once
#include "Fase.h"

namespace Fases {
	class Fase1 : public Fase {
	private:
		const int POS_MIN;
		const int POS_MAX;
	public:
		Fase1(bool AuxEh_1_jogador = true);
		~Fase1();
        void criarPersonagens();
        void criarObstaculos();
        void criarCachorros();
        void criarSoldado();
        void criarLenhadores();
        void criarPlataformas();
        void criarCaixas();
        void executar();
        void esvaziar();

	};
}
