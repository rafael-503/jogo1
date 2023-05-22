#pragma once
#include "Fase.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Personagens/Cachorro.h"
#include "../Entidades/Personagens/Lenhador.h"
#include "../Entidades/Personagens/Soldado.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"
#include "../Entidades/Obstaculos/Caixa.h"

namespace Fases {
	class Fase1 : public Fase {
	public:
		Fase1();
		~Fase1();
		void executar();
		void criarEntidades();
		void criarObstaculos();
	};
}
