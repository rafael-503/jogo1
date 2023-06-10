#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "../Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Personagem : public Entidade {
        protected:
            int vida;
            bool vivo;
        public:
            Personagem(sf::Vector2f tam_corpo);
            ~Personagem();
            void setVida(int AuxVida);
            int getVida() const;
            bool getVivo() const;
            virtual void salvar() = 0;
            virtual void executar() = 0;
            virtual void CarregarSe(string atributos) = 0;
        };
    }
}