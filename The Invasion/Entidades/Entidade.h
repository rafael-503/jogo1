#pragma once
#include "../stdafx.h"
#include "../Ente.h"
#include <SFML/Graphics.hpp>
using namespace std;

namespace Entidades{

    class Entidade: public Ente{
    protected:
        sf::Texture textura;
        sf::RectangleShape corpo;
        string Tipo;
        sf::Clock clockInteracao;
        sf::Vector2f pos;
        sf::Vector2f vel;
        bool SuspensoNoAR;
        int num;

    public:
        Entidade(sf::Vector2f tam_corpo);
        virtual ~Entidade();
        sf::RectangleShape getCorpo();
        void efeitoGravidade();
        const sf::Vector2f getPosition() const;
        const sf::Vector2f getSize() const;
        virtual string getTipo();
        void setVelocidade(sf::Vector2f v);
        sf::Vector2f getVelocidade() const;
        virtual void executar() = 0;
        void setSuspensoNoAR(bool aux);
        void mover(float moveX, float moveY);
        void setVelocidade_y(float aux);

    };
}
