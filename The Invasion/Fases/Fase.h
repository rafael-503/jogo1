#pragma once
#include "../Ente.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Cachorro.h"
#include "../Entidades/Obstaculos/Plataforma.h"

namespace Fases {
	class Fase : public Ente {
		protected:
			Gerenciadores::Gerenciador_Colisoes* pColisao;
			Listas::ListaEntidades listaObstaculos;
			Listas::ListaEntidades listaPersonagens;

		public:
			Fase();
			~Fase();
			void gerenciarColisoes();
			virtual void executar() = 0;
			virtual void criarPersonagens() = 0;
			virtual void criarObstaculos() = 0;
	};
}
