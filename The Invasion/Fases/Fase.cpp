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
    if(pEnti){
        listaPersonagens.remover(pEnti);
        Projetil* pProj = dynamic_cast<Projetil*>(pEnti);
        if(pProj)
            pColisao->removerProjetil(dynamic_cast<Projetil*>(pEnti));
        else
            cout << "Erro ao converter de Entidade para projetil" << endl;
    }
    else
        cout << "Erro ao converter de Entidade para projetil" << endl;

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
        construtorPersonagens("Lenhador", pos);
    else if(id == 3)
        construtorPersonagens("Cachorro", pos);
    else if(id == 4)
        construtorPersonagens("Soldado", pos);
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
void Fase::construtorPersonagens(const std::string& tipo, const sf::Vector2f& pos) {
    Entidades::Entidade* pEntidade = NULL;
    Entidades::Personagens::Inimigo* pInimigo = NULL;

    if (tipo == "Cachorro") {
        Entidades::Personagens::Cachorro* pCachorro = new Entidades::Personagens::Cachorro(pos);
        pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pCachorro);
    }
    else if (tipo == "Soldado") {
        Entidades::Personagens::Soldado* pSoldado = new Entidades::Personagens::Soldado(pos);
        pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pSoldado);
    }
    else if (tipo == "Lenhador") {
        Entidades::Personagens::Lenhador* pLenhador = new Entidades::Personagens::Lenhador(pos);
        pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pLenhador);
    }
    else {
        cout << "Erro: Tipo de personagem invalido" << endl;
        return;
    }

    if (pInimigo) {
        pColisao->incluiInimigo(pInimigo);
        pEntidade = static_cast<Entidade*>(pInimigo);
        listaPersonagens.inserir(pEntidade);
    }
}
void Fase::construtorObstaculos(const std::string& tipo, const sf::Vector2f& pos, sf::Vector2f tam) {
    Entidades::Obstaculos::Obstaculo* pObstaculo = NULL;
    Entidade* pEntidade = NULL;

    if (tipo == "Caixa")
        pObstaculo = new Entidades::Obstaculos::Caixa(pos);
    else if (tipo == "Espinhos")
        pObstaculo = new Entidades::Obstaculos::Espinhos(pos);
    else if (tipo == "Plataforma")
        pObstaculo = new Entidades::Obstaculos::Plataforma(pos, tam);
    else {
        cout << "Erro: Tipo de obstaculo invalido" << endl;
        return;
    }

    if (pObstaculo) {
        pColisao->incluiObstaculo(pObstaculo);
        pEntidade = static_cast<Entidade*>(pObstaculo);
        listaObstaculos.inserir(pEntidade);
    }
}

void Fase::criarJogadores(){

    Entidades::Entidade* pEntidade = NULL;
    pJogador1= new Entidades::Personagens::Jogador(sf::Vector2f(10.0f, 0.0f));
    if(!eh_1_jogador){
        pJogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(10.0f, 0.0f), sf::Vector2f(60.0f, 80.0f), JOGADOR2);
        pEntidade = static_cast<Entidade*> (pJogador2);
        listaPersonagens.inserir(pEntidade);
        pColisao->setJogador(pJogador2);
    }
    Inimigo::setPairpJogadores(pJogador1, pJogador2);
    pEntidade = static_cast<Entidade*> (pJogador1);
    listaPersonagens.inserir(pEntidade);
    pColisao->setJogador(pJogador1);


}
