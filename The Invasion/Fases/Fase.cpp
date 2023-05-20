#include "Fase.h"
using namespace Fases;

Fase::Fase(): pColisao(new Gerenciadores::Gerenciador_Colisoes()),listaObstaculos(), listaPersonagens(){
	executar();
}

Fase::~Fase() {
	if (pColisao) {
	delete pColisao;
		delete pColisao;
		pColisao = NULL;
	}
	listaObstaculos.esvaziar();
	listaPersonagens.esvaziar();
}

void Fase::gerenciarColisoes() {
	//pColisao->Calcula_colisao(listaPersonagens, listaObstaculos);
}

void Fase::executar() {
	listaObstaculos.executar();
	listaPersonagens.executar();

	gerenciarColisoes();
}