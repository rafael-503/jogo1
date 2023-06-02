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
 //   else
   //     cout << "mapEstados[EstadoAtual] nulo em executarEstadoAtual" << endl;

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

string GerenciadorEstado::getStringEstadoAtual() const{
    return EstadoAtual;
}

void GerenciadorEstado::crieEexecuteEstadoJogar(bool eh_fase1, bool eh_1_jogador){
    apagueEstadoJogar();
    mapEstados["EstadoJogar"] = new Estados::EstadoJogar(eh_fase1, eh_1_jogador);
    setEstadoAtual("EstadoJogar");

}
void GerenciadorEstado::apagueEstadoJogar(){
    //deletando EstadoJogar
    MapaStringEstado::iterator iterador = mapEstados.find("EstadoJogar");
    if (iterador != mapEstados.end()) {
        Estados::Menu* pAux = iterador->second;
        delete pAux;
    }
    mapEstados.erase("EstadoJogar");
}


/*
void GerenciadorEstado::setProximaFase() {
    resetarEstadoJogar();
    mapEstados["EstadoJogar"]->carregarFase2();
}

void GerenciadorEstado::trocarFase(bool fase1) {
	resetarEstadoJogar(fase1);
}
void GerenciadorEstado::resetarEstadoJogar(bool fase1){

    //deletando EstadoJogar
    MapaStringEstado::iterator iterador = mapEstados.find("EstadoJogar");
    if (iterador != mapEstados.end()) {
        Estados::Estado* pAux = iterador->second;
        delete pAux;
    }
    else
        cout << "Não achado EstadoJogar em resetarEstadoJogar" << endl;
    mapEstados["EstadoJogar"] = new Estados::EstadoJogar(true);

}

*/
