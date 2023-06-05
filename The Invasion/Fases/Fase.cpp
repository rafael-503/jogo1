#include "Fase.h"
using namespace Fases;
#define JOGADOR2 "The invasion/assets/personagem/jogador/personagem2.png"


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
void Fase::removerProjetil(Entidade* pEnti){
    listaPersonagens.remover(pEnti);
    pColisao->removerProjetil(static_cast<Projetil*>(pEnti));
}




void Fase::AdicionarProjetil(sf::Vector2f pos){

    Entidades::Projetil* pProjetil = NULL;
    pProjetil = new Entidades::Projetil(pos, pJogador1, pJogador2);
    Entidade* pEntidade = NULL;
    if(pProjetil)
        pEntidade = static_cast<Entidades::Entidade*> (pProjetil);
    else
        cout << "erro ao criar Projetil" << endl;
    listaPersonagens.inserir(pEntidade);
    pColisao->incluiProjetil(pProjetil);
    pProjetil->setFase(this);

}
void Fase::SalvarFase(std::ofstream* pGravadorFase){

    listaPersonagens.GravarSe(pGravadorFase);
    listaObstaculos.GravarSe(pGravadorFase);
}
void Fase::RecuperarFase(std::ifstream* pRecuperarFase){

    pColisao->limpar();
    pJogador1 = NULL;
    pJogador2 = NULL;
    listaPersonagens.esvaziar();
    listaObstaculos.esvaziar();

    while (!pRecuperarFase->eof()){
        int id;
        float posX, posY, tamX, tamY;
        *pRecuperarFase >> id >> posX >> posY >> tamX >> tamY;
        CarregarEntidades(id, sf::Vector2f(posX, posY), sf::Vector2f(tamX, tamY));
    }
    Inimigo::setPairpJogadores(pJogador1, pJogador2);

}
void Fase::CarregarEntidades(int id, sf::Vector2f pos, sf::Vector2f tam){

    if(id == 1)
        ConstrutorJogador(pos);
    else if(id == 2)
        construtorPersonagens("Lenhador", NULL, pos);
    else if(id == 3)
        construtorPersonagens("Cachorro", NULL, pos);
    else if(id == 4)
        construtorPersonagens("Soldado", NULL, pos);
    else if(id == 5)
        construtorObstaculos("Plataforma", pos, tam);
    else if(id == 6)
        construtorObstaculos("Caixa", pos);
    else if(id == 7)
        construtorObstaculos("Espinhos", pos);
    else if(id == 8)
        AdicionarProjetil(pos);
    else
        cout << "Carregando algo incalido em CarregarEntidades" << endl;



}
void Fase::ConstrutorJogador(sf::Vector2f pos){
    if(pJogador1 == NULL){
        pJogador1 = new Jogador(pos);
        pColisao->setJogador(pJogador1);
        listaPersonagens.inserir(static_cast<Entidade*>(pJogador1));
    }
    else if (pJogador2 == NULL){
        pJogador2 = new Jogador(pos, sf::Vector2f(60.0f, 80.0f), JOGADOR2);
        listaPersonagens.inserir(static_cast<Entidade*>(pJogador2));
        pColisao->setJogador(pJogador2);
    }
    else
        cout << "tentando criar mais de 2 Jogadores" << endl;

}
int Fase::getPontuacao() const{
    if(pJogador1 && pJogador2)
        return pJogador1->getPontuacao() + pJogador2->getPontuacao();
    else if(pJogador1)
        return pJogador1->getPontuacao();
    else
        cout << "pJogador1 nulo em Fase::getPontuacao" << endl;

}


