#include "ListaEntidades.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Gerenciadores/GerenciadorEstado.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../stdafx.h"
#include "../Fases/Fase.h"
#include "../Entidades/Personagens/Personagem.h"

using namespace Listas;
Gerenciadores::GerenciadorEstado* pGEstado = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();

ListaEntidades::ListaEntidades(){
}
ListaEntidades::~ListaEntidades(){
    // cout << "Destrutora ListaEntidades???" << endl;

}
void ListaEntidades::inserir(Entidade* pE){
    LEs.inserir(pE);
}

void ListaEntidades::remover(Entidade* pE) {
	LEs.remover(pE);
}

void ListaEntidades::percorrer(){
   for(int i = 0; i < LEs.getSize(); i++)
        cout << LEs[i]->getTipo() << endl;
}
void ListaEntidades::executar(){

    for(int i = 0; i < LEs.getSize(); i++)
        LEs[i]->executar();

}
void ListaEntidades::seDesenhe(){

    Gerenciadores::GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
    for(int i = 0; i < LEs.getSize(); i++)
        pGrafico->desenharElemento(LEs[i]->getCorpo());

}
int ListaEntidades::getSize() const{
    return LEs.getSize();
}
void ListaEntidades::esvaziar(){
    LEs.esvaziar();
}

void ListaEntidades::verificarVida(Gerenciadores::Gerenciador_Colisoes* pColisao) {

    Entidades::Personagens::Personagem* pPerso = NULL;
    for (int i = 0; i < LEs.getSize(); i++){
        pPerso = dynamic_cast<Entidades::Personagens::Personagem*>(LEs[i]);
        if(pPerso){
            if(!pPerso->getVivo() || pPerso->getPosition().y > 2000){
                /// se for o Jogador a fase acaba (perdeu)
                if(pPerso->getID() == 1){
                    Entidades::Personagens::Jogador* pJog = dynamic_cast<Entidades::Personagens::Jogador*>(pPerso);
                    pGEstado->setEstadoAtual("GameOver");
                    cout << "GAME OVER" << endl;

                }
                /// se for o Soldado (chefão) a fase termina
                else if(pPerso->getID() == 4){
                    pGEstado->guardarPontuacao();
                    pGEstado->setEstadoAtual("MenuSalvarPontuacao");
                }

                apagarElemento(static_cast<Entidades::Entidade*>(pPerso), pColisao);
            }
        }
        //ainda a projeteis nessa lista TEMPORARIO
        else if(LEs[i]->getID() == 8);
        else
            cout << "pPerso nulo em verificarVida" << endl;

    }


}
void ListaEntidades::GravarSe(ofstream* pArquivo){
    for (int i = 0; i < LEs.getSize(); i++){
        *pArquivo << LEs[i]->getID() << ' ' << LEs[i]->getPosition().x << ' '<< LEs[i]->getPosition().y
            << ' ' <<  LEs[i]->getSize().x << ' ' << LEs[i]->getSize().y << endl;
    }
}
void ListaEntidades::apagarElemento(Entidades::Entidade* pEnti, Gerenciadores::Gerenciador_Colisoes* pColisao){
    remover(pEnti);
    pColisao->RetirarElemento(pEnti);
    delete pEnti;
}
