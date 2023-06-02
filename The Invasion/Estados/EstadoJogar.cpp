#include "../Gerenciadores/GerenciadorEstado.h"
#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(bool eh_fase1, bool eh_1_jogador): Menu(), pFase(NULL) {

    if(eh_fase1)
		pFase = static_cast<Fases::Fase*> (new Fases::Fase1(eh_1_jogador));
    else
        pFase = static_cast<Fases::Fase*> (new Fases::Fase2(eh_1_jogador));

	PrimeiroExecutar();
}
EstadoJogar::~EstadoJogar(){
    //if (pFase)
	  //  delete pFase;
    pFase = NULL;
}
void EstadoJogar::executar(){
    if(pFase)
        pFase->executar();
    else
        cout << "Erro: pFase nulo" << endl;
}
void EstadoJogar::PrimeiroExecutar(){
    if (dynamic_cast<Fases::Fase1*>(pFase) != NULL)
	    pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
   else
        pGrafico->carregarFundo("The invasion/assets/fundo/fundo2.png");
}
void EstadoJogar::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::Escape)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPrincipal");
    else if(tecla == sf::Keyboard::P)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPause");
    else
        pFase->TeclaPressionada(tecla);
}

void EstadoJogar::carregarFase2() {
	pFase->executar();
}
