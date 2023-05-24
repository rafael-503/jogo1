#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../stdafx.h"

namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* window;
		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();
		sf::View view;

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		void limparJanela();
		void desenharElemento(sf::RectangleShape corpo);
		void desenharElemento(sf::Text texto);
		void mostrarElementos();
		void fecharJanela();
		void setView(sf::View view);
		const bool verificarJanelaAberta();
		sf::Texture carregarTextura(const char* caminho);
		void carregarFundo(const std::string& caminho);
	};
}
