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
		void executar();
		void esvaziar();
		void construtorObstaculos(const std::string& tipo, const sf::Vector2f& pos, sf::Vector2f tam = sf::Vector2f(200.0f, 50.0f));
		void construtorPersonagens(const std::string& tipo, Entidades::Personagens::Jogador* pJogador, const sf::Vector2f& pos);
		void criarPersonagens();
		void criarObstaculos();
	};
}
