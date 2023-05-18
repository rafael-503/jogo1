#pragma once
#include "../stdafx.h"
#include "../Ente.h"
#include <SFML/Graphics.hpp>
using namespace std;

namespace Entidades{

    class Entidade: public Ente{
    protected:
        string Tipo;
        sf::RectangleShape corpo;
        sf::Clock relogio;
        sf::Vector2f pos;
        sf::Vector2f vel;
        sf::Texture textura;

    public:
        Entidade(sf::Vector2f tam_corpo, string tipo);
        ~Entidade();
        sf::RectangleShape getCorpo();
        const sf::Vector2f getPosition() const;
        const sf::Vector2f getSize() const;
        virtual void colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x);
        virtual string getTipo();
        void setVelocidade(sf::Vector2f v);
        virtual void executar() = 0;
    };
}
