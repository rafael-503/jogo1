#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.h"

class Ente{
    protected:
        int id;
        static Gerenciadores::GerenciadorGrafico* pGrafico;

    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;
        void desenhar();
};

