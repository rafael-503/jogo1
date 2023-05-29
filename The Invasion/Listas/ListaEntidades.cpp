#include "ListaEntidades.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Gerenciadores/GerenciadorEstado.h"
#include "../stdafx.h"

using namespace Listas;
Gerenciadores::GerenciadorEstado* pEstado = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();

ListaEntidades::ListaEntidades(){
}
ListaEntidades::~ListaEntidades(){

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

void ListaEntidades::verificarVida() {
    for (int i = 0; i < LEs.getSize(); i++) {
        Entidade* pE = LEs[i];
        if (pE) {
            if (pE->getVida() <= 0) {
                if (dynamic_cast<Entidades::Personagens::Jogador*>(pE) != NULL) {
                    
                    cout << pE->getPontuacao() << endl;
                    pEstado->guardarPontuacao(pE->getPontuacao());
                    pEstado->setEstadoAtual("GameOver");
                    cout << "GAME OVER" << endl;
                }
                LEs.remover(pE);
                i--;
            }

            if (pE->getPosition().y > 2000) {
                if (dynamic_cast<Entidades::Personagens::Jogador*>(pE) != NULL) {
                    cout << pE->getPontuacao() << endl;
                    pEstado->guardarPontuacao(pE->getPontuacao());
                    pEstado->setEstadoAtual("GameOver");
                    cout << "GAME OVER" << endl;
                }
                pE->setVida(0);
                LEs.remover(pE);
                i--;
            }
        }
    }
}