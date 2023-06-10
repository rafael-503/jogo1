#include "../../stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>

Entidades::Personagens::Personagem::Personagem(sf::Vector2f tam_corpo) :
  Entidade(tam_corpo), vida(100), vivo(true) {
    setVelocidade(sf::Vector2f(0.0f, 0.0f));
}

Entidades::Personagens::Personagem::~Personagem() {}

void Entidades::Personagens::Personagem::setVida(int AuxVida) {
    vida = AuxVida;
    if(vida < 0)
		vivo = false;
}

int Entidades::Personagens::Personagem::getVida() const {
	return vida;
}

bool Entidades::Personagens::Personagem::getVivo() const{
    return vivo;
}