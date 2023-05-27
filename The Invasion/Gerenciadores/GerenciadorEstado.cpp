#include "GerenciadorEstado.h"
using namespace Gerenciadores;

GerenciadorEstado* GerenciadorEstado::pEstados = NULL;
GerenciadorEstado::GerenciadorEstado(): EstadoAtual("MenuPrincipal"){
    //mapEstados["Fase"] = new Fases::Fase1();
    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
    mapEstados["MenuPrincipal"] = new Estados::MenuPrincipal();
    mapEstados[EstadoAtual]->PrimeiroExecutar();
}
GerenciadorEstado::~GerenciadorEstado(){

}
GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
    if (pEstados == NULL)
        pEstados = new GerenciadorEstado();
    return pEstados;
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
