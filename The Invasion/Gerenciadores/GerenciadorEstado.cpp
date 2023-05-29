#include "GerenciadorEstado.h"
using namespace Gerenciadores;

GerenciadorEstado* GerenciadorEstado::pGEstados = NULL;
GerenciadorEstado::GerenciadorEstado(): EstadoAtual("MenuPrincipal"){

    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
    mapEstados["MenuPause"] = new Estados::MenuPause();
    mapEstados["GameOver"] = new Estados::GameOver();
    mapEstados["MenuPrincipal"] = new Estados::MenuPrincipal();
    mapEstados["Ranking"] = new Estados::Ranking();
    mapEstados[EstadoAtual]->PrimeiroExecutar();
    mapEstados[EstadoAtual]->setExecutando(true);
}
GerenciadorEstado::~GerenciadorEstado(){

}
GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
    if (pGEstados == NULL)
        pGEstados = new GerenciadorEstado();
    return pGEstados;
}
void GerenciadorEstado::executarEstadoAtual(){
//    if(mapEstados.contains(EstadoAtual))
        mapEstados[EstadoAtual]->executar();

}
void GerenciadorEstado::setEstadoAtual(string estadoAux){
    mapEstados[EstadoAtual]->setExecutando(false);
    EstadoAtual = estadoAux;
    mapEstados[EstadoAtual]->PrimeiroExecutar();
    mapEstados[EstadoAtual]->setExecutando(true);

}
void GerenciadorEstado::TeclaPressionada(const sf::Keyboard::Key tecla){
    mapEstados[EstadoAtual]->TeclaPressionada(tecla);
}

void GerenciadorEstado::guardarPontuacao(int num) {
    mapEstados["Ranking"]->guardarPontuacao(num);
}

void GerenciadorEstado::resetarEstadoJogar() {
    mapEstados.erase("EstadoJogar");
    delete mapEstados["EstadoJogar"];
    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
    mapEstados["EstadoJogar"]->PrimeiroExecutar();
    mapEstados["EstadoJogar"]->setExecutando(true);

}