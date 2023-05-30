#pragma once
#include "Fase.h"

namespace Fases {
	class Fase2 : public Fase {
	private:
		const int POS_MIN;
		const int POS_MAX;

	public:
		Fase2();
		~Fase2();
		void executar();
		void esvaziar();
		void construtorObstaculos(const std::string& tipo, const sf::Vector2f& tam, const sf::Vector2f& pos);
		void construtorPersonagens(const std::string& tipo, Entidades::Personagens::Jogador* pJogador, const sf::Vector2f& tam, const sf::Vector2f& poss);
		void criarPersonagens();
		void criarObstaculos();
	};
}
