#include "Fase.h"
using namespace Fases;

Fase::Fase(): pColisao((pColisao->getGerenciador_Colisoes())) {
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