#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>



class Ente{
    protected:

    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;

};

