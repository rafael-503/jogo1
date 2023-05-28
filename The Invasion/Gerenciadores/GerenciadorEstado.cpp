#include "GerenciadorEstado.h"
using namespace Gerenciadores;

GerenciadorEstado* GerenciadorEstado::pGEstados = NULL;
GerenciadorEstado::GerenciadorEstado(): EstadoAtual("MenuPrincipal"){

    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
    mapEstados["MenuPause"] = new Estados::MenuPause();
    mapEstados["MenuPrincipal"] = new Estados::MenuPrincipal();
    mapEstados[EstadoAtual]->PrimeiroExecutar();
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
    EstadoAtual = estadoAux;
    mapEstados[EstadoAtual]->PrimeiroExecutar();

}
void GerenciadorEstado::TeclaPressionada(const sf::Keyboard::Key tecla){
    mapEstados[EstadoAtual]->TeclaPressionada(tecla);
}
