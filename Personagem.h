#pragma once
#include <SFML/Graphics.hpp>

class Personagem{
    private:
        float x, y;
        sf::Texture* textura;
        sf::RectangleShape corpo;
    public:
        Personagem(float xInicial= 0.0f, float yInicial= 0.0f, const char* caminhoTextura= nullptr);
        ~Personagem();
        void atualizar();
        void desenhar(sf::RenderWindow* janela);

};