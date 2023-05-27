#include "Fase.h"
using namespace Fases;

Fase::Fase(): pColisao(pColisao->getGerenciador_Colisoes()), pJogador(NULL){

}

Fase::~Fase() {
	if (pColisao) {
		delete pColisao;
		pColisao = NULL;
	}
	listaObstaculos.esvaziar();
	listaPersonagens.esvaziar();
}

void Fase::gerenciarColisoes() {
	//pColisao->Calcula_colisao(listaPersonagens, listaObstaculos);
}
void Fase::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(pJogador){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pJogador->move(false, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pJogador->move(true, false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            pJogador->move(false, true);
        setPosicaoJogador(pJogador->getPosition());
    }
    else
        cout << "pJogador Nulo" << endl;


}
void Fase::setPosicaoJogador(const sf::Vector2f& jogadorPos) {
    pGrafico->atualizarView(jogadorPos);
}
