#include "../Gerenciadores/GerenciadorEstado.h"
#include "EstadoJogar.h"
using namespace Estados;
#include "../stdafx.h"

//temporario
#include "../Entidades/Personagens/Inimigo.h"


EstadoJogar::EstadoJogar(bool eh_fase1, bool eh_1_jogador): Menu(), pFase(NULL), Eh_fase1(eh_fase1), Eh_1_Jogador(eh_1_jogador) {

    if(eh_fase1)
		pFase = static_cast<Fases::Fase*> (new Fases::Fase1(eh_1_jogador));
    else
        pFase = static_cast<Fases::Fase*> (new Fases::Fase2(eh_1_jogador));

	PrimeiroExecutar();
}
EstadoJogar::EstadoJogar(ifstream* pRecuperadorFase){
    *pRecuperadorFase >> Eh_fase1 >> Eh_1_Jogador;
    if(Eh_fase1)
		pFase = static_cast<Fases::Fase*> (new Fases::Fase1(Eh_1_Jogador));
    else
        pFase = static_cast<Fases::Fase*> (new Fases::Fase2(Eh_1_Jogador));

    pFase->RecuperarFase(pRecuperadorFase);
	PrimeiroExecutar();
}




EstadoJogar::~EstadoJogar(){
    //if (pFase)
	  //  delete pFase;
    pFase = NULL;


    //temporario por causa do delete de cima bugado
    Inimigo::limparPairpJogadores();
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
bool EstadoJogar::getEh_fase1() const{
    return Eh_fase1;
}
bool EstadoJogar::getEh_1_Jogador() const{
    return Eh_1_Jogador;
}
void EstadoJogar::salvarFase(){
    std::ofstream GravadorFase("Fase.txt", ios::out);
    if (!GravadorFase){
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush (stdin);
        getchar ();
        return;
    }
    /// Primeira linha tem o se é fase1 ou fase2 e se é 1 ou dois jogadores
    GravadorFase << Eh_fase1 << ' ' << Eh_1_Jogador << endl;
    pFase->SalvarFase(&GravadorFase);
    GravadorFase.close();
}
