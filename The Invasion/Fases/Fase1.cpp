#include "Fase1.h"
using namespace Fases;

Fase1::Fase1() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
	criarPersonagens();
	criarObstaculos();
}

Fase1::~Fase1() {

}

void Fase1::atualizar() {
	listaPersonagens.executar();
	listaObstaculos.executar();

	listaPersonagens.seDesenhe();
	listaObstaculos.seDesenhe();
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
}

void Fase1::criarPersonagens() {

}

void Fase1::criarObstaculos() {

}