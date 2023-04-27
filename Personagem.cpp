#include "Personagem.h"
#include <iostream>

Personagem::Personagem(float xInicial, float yInicial, const char* caminhoTextura): 
 x(xInicial), y(yInicial), textura(nullptr){
    textura = new sf::Texture;
    if (!textura->loadFromFile(caminhoTextura)){
        std::cout << "Não foi possível carregar a textura " << caminhoTextura << std::endl;
    }
    corpo.setTexture(textura);
    corpo.setSize(sf::Vector2f(200.0f, 200.0f));
    corpo.setOrigin(corpo.getSize() / 2.0f);
}

Personagem::~Personagem(){
    if(textura) 
        delete textura;
}

void Personagem::atualizar(){
    x += 0.0008;
    y += 0.0006;
    corpo.setPosition(sf::Vector2f(x, y));
}

void Personagem::desenhar(sf::RenderWindow* janela){
    janela->draw(corpo);
};
