#pragma once
#include "../stdafx.h"
#include "../Estados/Estado.h"
#include "../Estados/MenuPrincipal.h"
#include "../Estados/EstadoJogar.h"
#include "../Estados/MenuPause.h"
#include "../Estados/GameOver.h"
#include "../Estados/Ranking.h"
#include "../Fases/Fase1.h"
#include <map>

typedef map< string, Estados::Estado*> MapaStringEstado;

namespace Gerenciadores{

    class GerenciadorEstado{
        private:
            MapaStringEstado mapEstados;
            string EstadoAtual;
            //singleton
            GerenciadorEstado();
        public:
            static GerenciadorEstado* pGEstados;
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executarEstadoAtual();
            void setEstadoAtual(string estadoAux);
			void TeclaPressionada(const sf::Keyboard::Key tecla);
            void guardarPontuacao(int num);
            void resetarEstadoJogar();
            string getStringEstadoAtual() const;
            void setProximaFase();
    };

}
