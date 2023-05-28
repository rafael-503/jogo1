#include "ListaEntidades.h"
#include "../stdafx.h"
using namespace Listas;

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
        if (pE->getVida() < 0) {
            LEs.remover(pE);
            i--;  // Atualiza o índice para percorrer corretamente após a remoção
        }
    }
}




