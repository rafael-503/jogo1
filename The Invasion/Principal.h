#pragma once
#include "stdafx.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/GerenciadorEvento.h"
#include "Gerenciadores/GerenciadorEstado.h"
#include "Listas/ListaEntidades.h"

class Principal {
    private:
        Gerenciadores::GerenciadorGrafico* pGrafico;
        Gerenciadores::Gerenciador_Colisoes* pGerencia_Colisoes;
        Gerenciadores::GerenciadorEvento* pGerenciaEventos;
        Gerenciadores::GerenciadorEstado* pEstados;

    public:
        Principal();
        ~Principal();
        void executar();


};
