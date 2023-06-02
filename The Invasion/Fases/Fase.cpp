#include "Fase.h"
using namespace Fases;

Fase::Fase(): eh_1_jogador(true), pColisao(pColisao->getGerenciador_Colisoes()), pJogador1(NULL), pJogador2(NULL), relogioAtirar(){
	pColisao->limpar();
}

Fase::~Fase() {

	pColisao = NULL;
	listaObstaculos.esvaziar();
	listaPersonagens.esvaziar();
}

void Fase::gerenciarColisoes() {
	//pColisao->Calcula_colisao(listaPersonagens, listaObstaculos);
}
void Fase::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(pJogador1){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pJogador1->Mover_Se(false, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pJogador1->Mover_Se(true, false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            pJogador1->Mover_Se(false, true);
        setPosicaoJogador(pJogador1->getPosition());
    }
    else
        cout << "pJogador1 Nulo" << endl;


    if (pJogador2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pJogador2->Mover_Se(false, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pJogador2->Mover_Se(true, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            pJogador2->Mover_Se(false, true);
        setPosicaoJogador(pJogador2->getPosition());
    }
}
void Fase::setPosicaoJogador(const sf::Vector2f& jogadorPos) {
    pGrafico->atualizarView(jogadorPos);
}
void Fase::inimigosAtirar(){

    if(relogioAtirar.getElapsedTime().asSeconds() > 10.0f){
        Entidades::Projetil* pProjetil = NULL;
        pProjetil = new Entidades::Projetil(sf::Vector2f(100.0f , 100.0f), pJogador1, pJogador2);
        Entidade* pEntidade = NULL;
        if(pProjetil)
            pEntidade = static_cast<Entidades::Entidade*> (pProjetil);
        else
            cout << "erro ao criar Projetil" << endl;
        listaPersonagens.inserir(pEntidade);
        relogioAtirar.restart();
    }
}

