#include "../Gerenciadores/GerenciadorEstado.h"
#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(): fase1(){

}
EstadoJogar::~EstadoJogar(){
    cout << "TESTE" << endl;
}
void EstadoJogar::executar(){
    fase1.executar();
}
void EstadoJogar::PrimeiroExecutar(){
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
}
void EstadoJogar::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::Escape)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPrincipal");
    else if(tecla == sf::Keyboard::P)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPause");
    else
        fase1.TeclaPressionada(tecla);
}
