#include "../../stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>

Entidades::Personagens::Personagem::Personagem(sf::Vector2f tam_corpo) :
  Entidade(tam_corpo), vida(100) {
    setVelocidade(sf::Vector2f(0.0f, 0.0f));
}

Entidades::Personagens::Personagem::~Personagem() {}

int Entidades::Personagens::Personagem::getVida() const {
	return vida;
}

void Entidades::Personagens::Personagem::setVida(int vida) {
	this->vida = vida;
}

void Entidades::Personagens::Personagem::atacar() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

	}
}