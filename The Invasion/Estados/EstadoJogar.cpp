#include "../Gerenciadores/GerenciadorEstado.h"
#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(bool fase1): pFase(NULL){
    if(fase1)
		pFase = new Fases::Fase1();
    else{
        if (pFase) {
           delete pFase;
           pFase = NULL;
           cout << "deletado fase1" << endl;
        }
       cout << "criado Fase 2" << endl;
		pFase = new Fases::Fase2();
    }
	PrimeiroExecutar();
}
EstadoJogar::~EstadoJogar(){
   // if (pFase)
	 //   delete pFase;
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
        pGrafico->carregarFundo("The invasion/assets/fundo/fundoRanking.png");
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
