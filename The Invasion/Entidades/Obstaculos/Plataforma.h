#pragma once
#include "Obstaculo.h"
#define PLATAFORMA "The invasion/assets/obstaculos/plataforma1.png"
#define PLATAFORMA4 "The invasion/assets/obstaculos/plataforma4.png"
#define PLATAFORMA5 "The invasion/assets/obstaculos/plataforma5.png"

namespace Entidades {
    namespace Obstaculos {

        class Plataforma: public Obstaculo{
        private:
            bool curador;

        public:
            Plataforma(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(200.0f, 50.0f), const char* text= PLATAFORMA);
            ~Plataforma();
            void executar();
            void obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X);
            void obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X);
            void obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X);
            void ColidirPlataforma(Entidade* pEnti, sf::Vector2f DistExtremidades, bool colidiu_X);
            void salvar();
            void CarregarSe(string atributos);
        };
    }
}