#pragma once
#include "../Ente.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"

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
			virtual void atualizar() = 0;
			virtual void esvaziar() = 0;
			virtual void criarPersonagens() = 0;
			virtual void criarObstaculos() = 0;
	};
}
