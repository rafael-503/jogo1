#pragma once
#include "stdafx.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"

class Principal {
    private:
        Gerenciadores::GerenciadorGrafico* pGrafico;
    public:
        Principal();
        ~Principal();
        void executar();


};
