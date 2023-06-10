#include "GerenciadorEstado.h"
using namespace Gerenciadores;
#include "../Estados/EstadoJogar.h"

GerenciadorEstado* GerenciadorEstado::pGEstados = NULL;
GerenciadorEstado::GerenciadorEstado(): EstadoAtual("MenuPrincipal"){

    mapEstados["EstadoJogar"] = new Estados::EstadoJogar();
    mapEstados["MenuPause"] = new Estados::MenuPause();
    mapEstados["GameOver"] = new Estados::GameOver();
    mapEstados["MenuPrincipal"] = new Estados::MenuPrincipal();
    mapEstados["Ranking"] = new Estados::Ranking();
    mapEstados["MenuSalvarPontuacao"] = new Estados::MenuSalvarPontuacao(dynamic_cast<Estados::Ranking*>(mapEstados["Ranking"]));
    mapEstados[EstadoAtual]->PrimeiroExecutar();
    mapEstados[EstadoAtual]->setExecutando(true);
}

GerenciadorEstado::~GerenciadorEstado(){}

GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
    if (pGEstados == NULL)
        pGEstados = new GerenciadorEstado();
    return pGEstados;
}

void GerenciadorEstado::executarEstadoAtual(){
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

void GerenciadorEstado::guardarPontuacao() {
    Estados::EstadoJogar* pJogar = dynamic_cast<Estados::EstadoJogar*>(mapEstados["EstadoJogar"]);
    Estados::MenuSalvarPontuacao* pMenuSalvar = dynamic_cast<Estados::MenuSalvarPontuacao*>(mapEstados["MenuSalvarPontuacao"]);
    pMenuSalvar->AdicionarPontuacao(pJogar->getPontuacao());
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

void GerenciadorEstado::ReiniciarEstadoJogar(){
    Estados::EstadoJogar* pAux = dynamic_cast<Estados::EstadoJogar*>(mapEstados["EstadoJogar"]);
    crieEexecuteEstadoJogar(pAux->getEh_fase1(), pAux->getEh_1_Jogador());
}

void GerenciadorEstado::salvarFase(){
    Estados::EstadoJogar* pAux = dynamic_cast<Estados::EstadoJogar*>(mapEstados["EstadoJogar"]);
    pAux->salvarFase();
}

void GerenciadorEstado::RecuperareExecutarFase(){
    apagueEstadoJogar();

    ifstream RecuperadorFase("Fase.txt", ios::in);
    if (!RecuperadorFase){
        cerr << "Arquivo não pode ser aberto" << endl;
    }

    mapEstados["EstadoJogar"] = new Estados::EstadoJogar(&RecuperadorFase);
    setEstadoAtual("EstadoJogar");

    RecuperadorFase.close();
}