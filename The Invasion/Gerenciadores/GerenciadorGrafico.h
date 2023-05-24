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
		sf::Texture* pTextFundo;

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		void limparJanela();
		void desenharElemento(sf::RectangleShape corpo);
		void desenharElemento(sf::Text texto);
		void desenharElemento(sf::Sprite sprite);
		void mostrarElementos();
		void fecharJanela();
		void setView(sf::View view);
		const bool verificarJanelaAberta();
		sf::Texture carregarTextura (const char* caminho);
		sf::Sprite carregarFundo(const char* caminho);
	};
}
