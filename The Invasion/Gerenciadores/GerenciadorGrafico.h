#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* window;
		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		void limparJanela();
		void desenharElemento(sf::RectangleShape corpo);
		void mostrarElementos();
		void fecharJanela();
		const bool verificarJanelaAberta();
	};
}