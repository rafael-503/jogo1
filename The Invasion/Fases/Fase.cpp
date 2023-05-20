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

void Fase::carregarFundo(const std::string& caminho) {
	sf::Sprite sprite;
	sprite.setTexture(pGrafico->carregarTextura(caminho.c_str()));
	sprite.setPosition(0, 0);

	sf::Vector2u windowSize = pGrafico->getWindow()->getSize();
	sprite.setScale(
		static_cast<float>(windowSize.x) / sprite.getTexture()->getSize().x,
		static_cast<float>(windowSize.y) / sprite.getTexture()->getSize().y
	);
	pGrafico->getWindow()->draw(sprite);
}


void Fase::executar() {
	listaObstaculos.executar();
	listaPersonagens.executar();

	gerenciarColisoes();
}