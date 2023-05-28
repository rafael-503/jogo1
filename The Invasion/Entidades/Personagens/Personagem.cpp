#include "../../stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>

Entidades::Personagens::Personagem::Personagem(sf::Vector2f tam_corpo) :
  Entidade(tam_corpo){
    setVelocidade(sf::Vector2f(0.0f, 0.0f));
}

Entidades::Personagens::Personagem::~Personagem() {
}