#include "GerenciadorEstado.h"
using namespace Gerenciadores;

GerenciadorEstado* GerenciadorEstado::pEstados = NULL;
GerenciadorEstado::GerenciadorEstado(): EstadoAtual("EstadoJogar"){
    //mapEstados["Fase"] = new Fases::Fase1();
    mapEstados["MenuPrincipal"] = new Estados::MenuPrincipal();
    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
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
void GerenciadorEstado::setEstadoAtual(string& estadoAux){
    EstadoAtual = estadoAux;
}
