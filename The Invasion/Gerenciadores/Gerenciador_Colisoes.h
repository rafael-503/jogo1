#pragma once
#include "../stdafx.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Missil.h"
#include <SFML/Graphics.hpp>
#include <list>
using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores {

    class Gerenciador_Colisoes {
    private:
        static Gerenciador_Colisoes* pGerenciador_Colisoes;
        std::pair<Personagens::Jogador*, Personagens::Jogador*> pJogadores;
        vector<Personagens::Inimigo*> vetor_inimigos;
        list<Obstaculos::Obstaculo*> lista_obstaculos;
        list<Missil*> lista_Misseis;

    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();
        void incluiPersonagem(Personagem* pPerso);
        void incluiInimigo(Inimigo* pInimigo);
        void incluiObstaculo(Obstaculos::Obstaculo* pObs);
        void incluiProjetil(Missil* pProj);
        void removerProjetil(Missil* pProj);
        void testa_colisoes();
        void ColisaoInimigoObstaculo();
        void ColisaoJogadorObstaculo();
        void ColisaoJogadorInimigo();
        void ColisaoEntreObstaculos();
        void ColisaoProjetilEntidade();
        void setJogador(Jogador* pJogaAux);
        void limpar();
        void RetirarInimigo(Entidades::Personagens::Inimigo* pInimigo);
        void RetirarJogador(Entidades::Personagens::Jogador* pJogador);
        void RetirarObstaculo(Entidades::Obstaculos::Obstaculo* pObs);
        void RetirarElemento(Entidades::Entidade* pEnti);
        sf::Vector2f Calcula_colisao(Entidade* pEnti1, Entidade* pEnti2);
        Gerenciador_Colisoes* getGerenciador_Colisoes();
    };
}