#pragma once
#include "Fase.h"

namespace Fases {
	class Fase1 : public Fase {
	private:
		const int POS_MIN;
		const int POS_MAX;
	public:
		Fase1();
		~Fase1();
		void executar();
		void esvaziar();
		void construtorObstaculos(const std::string& tipo, const sf::Vector2f& tam, const sf::Vector2f& pos);
		void construtorPersonagens(const std::string& tipo, Entidades::Personagens::Jogador* pJogador, const sf::Vector2f& pos);
		void criarPersonagens();
		void criarObstaculos();
	};
}