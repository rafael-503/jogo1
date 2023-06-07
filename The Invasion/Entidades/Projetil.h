#pragma once
#include "../stdafx.h"
#include "Entidade.h"
#include "SFML/Graphics.hpp"
#include "Personagens/Jogador.h"
#define PROJETIL "The invasion/assets/inimigo/soldado/projetil.png"

namespace Fases{
    class Fase;
}

namespace Entidades{

    class Projetil: public Entidade{
        private:
            float vel_projetil;
            Personagens::Jogador* pPerseguido;
            Fases::Fase* pFase;
            int dano;

        public:
            Projetil(sf::Vector2f posInimigo, Personagens::Jogador* pJogador1 = NULL, Personagens::Jogador* pJogador2 = NULL);
            ~Projetil();
            void executar();
            void setFase(Fases::Fase* pFaseAux);
            void AcertouJogador(Entidades::Personagens::Jogador* pJog);
            void ApagarProjetil();
            void salvar();
            void CarregarSe(string atributos);

    };
}
