#include "Fase2.h"
using namespace Fases;

Fase2::Fase2() {
	//pGrafico->carregarFundo("The invasion/assets/fundo/fundo2.png");
	criarPersonagens();
	criarObstaculos();
}

Fase2::~Fase2() {

}

void Fase2::executar() {
	listaObstaculos.executar();
	listaPersonagens.executar();

	//gerenciarColisoes();
}

void Fase2::criarPersonagens() {

}

void Fase2::criarObstaculos() {

}