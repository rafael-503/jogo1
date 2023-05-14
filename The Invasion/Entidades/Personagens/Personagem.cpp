#include "../../stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>



Entidades::Personagens::Personagem::Personagem(sf::Vector2f tam_corpo, string tipo) :
    Entidade(tam_corpo, tipo)
{}

Entidades::Personagens::Personagem::~Personagem() {}