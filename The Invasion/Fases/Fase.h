#pragma once
#include "../Ente.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Personagens/Jogador.h"
// Inimigos
#include "../Entidades/Personagens/Cachorro.h"
#include "../Entidades/Personagens/Soldado.h"
#include "../Entidades/Personagens/Lenhador.h"
// Obstaculos
#include "../Entidades/Obstaculos/Caixa.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"

//Projetil
#include "../Entidades/Projetil.h"

namespace Fases {
	class Fase : public Ente {
		protected:
		    bool eh_1_jogador;
			Gerenciadores::Gerenciador_Colisoes* pColisao;
			Listas::ListaEntidades listaObstaculos;
			Listas::ListaEntidades listaPersonagens;
            Entidades::Personagens::Jogador* pJogador1;
			Entidades::Personagens::Jogador* pJogador2;
            sf::Clock relogioAtirar;


		public:
			Fase();
			virtual ~Fase();
			void gerenciarColisoes();
			void TeclaPressionada(const sf::Keyboard::Key tecla);
			void setPosicaoJogador(const sf::Vector2f& jogadorPos);
			void removerProjetil(Entidade* pEnti);
			void AdicionarProjetil(sf::Vector2f pos);
			void SalvarFase(std::ofstream* pGravadorFase);
			void RecuperarFase();
			int getPontuacao() const;
			void limparArquivos();
			void CarregarEntidades(int id, sf::Vector2f pos, sf::Vector2f tam);
            void ConstrutorJogador(sf::Vector2f pos);
            void construtorObstaculos(const std::string& tipo, const sf::Vector2f& pos, sf::Vector2f tam = sf::Vector2f(200.0f, 50.0f));
            void construtorPersonagens(const std::string& tipo, const sf::Vector2f& pos);
            void criarJogadores();
            void RecuperarObstaculos();
            void RecuperarPersonagens();
			virtual void criarPersonagens() = 0;
			virtual void criarObstaculos() = 0;
            virtual void criarCachorros() = 0;
            virtual void criarSoldado() = 0;
            virtual void criarLenhadores() = 0;
            virtual void criarPlataformas() = 0;
            virtual void criarCaixas() = 0;
            virtual void executar() = 0;
			virtual void esvaziar() = 0;

	};
}
