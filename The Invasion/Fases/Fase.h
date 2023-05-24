#pragma once
#include "../Ente.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Gerenciadores/GerenciadorEvento.h"
#include "../Entidades/Personagens/Jogador.h"
// Inimigos
#include "../Entidades/Personagens/Cachorro.h"
#include "../Entidades/Personagens/Soldado.h"
#include "../Entidades/Personagens/Lenhador.h"
// Obstaculos
#include "../Entidades/Obstaculos/Caixa.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"

namespace Fases {
	class Fase : public Ente {
		protected:
			Gerenciadores::Gerenciador_Colisoes* pColisao;
			Gerenciadores::GerenciadorEvento* pEventos;
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
