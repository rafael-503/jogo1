#pragma once
#include "../Ente.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"

namespace Fases {
	class Fase : public Ente {
		protected:
			Gerenciadores::Gerenciador_Colisoes* pColisao;
			Listas::ListaEntidades listaPersonagens;
			Listas::ListaEntidades listaObstaculos;
			sf::Texture texture;
			sf::Sprite sprite;

		public:
			Fase();
			~Fase();
			void gerenciarColisoes();
			void carregarFundo(const std::string& caminho);
			virtual void executar();
			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;
	};
}