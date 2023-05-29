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
        sf::Clock relogio;
        sf::Vector2f pos;
        sf::Vector2f vel;
        bool SuspensoNoAR;
        float massa;
        int vida;
        int pontuacao;

    public:
        Entidade(sf::Vector2f tam_corpo);
        virtual ~Entidade();
        sf::RectangleShape getCorpo();
        float getMassa() const;
        void setMassa(float Massa);
        void efeitoGravidade();
        const sf::Vector2f getPosition() const;
        const sf::Vector2f getSize() const;
        virtual void colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x);
        virtual string getTipo();
        void setVelocidade(sf::Vector2f v);
        virtual void executar() = 0;
        void setVida(int vida);
        int getVida() const;
        void setPontuacao(int pontuacao);
        int getPontuacao() const;
    };
}
