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
	listaMisseis.esvaziar();
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
void Fase::removerProjetil(Entidades::Projetil* pMissil){

    if (pMissil){
        pColisao->removerProjetil(pMissil);
        Entidade* pEnti = dynamic_cast<Entidade*>(pMissil);
        if(pEnti)
            listaMisseis.remover(pEnti);
        else
            cout << "Erro ao converter de projetil para Entidade" << endl;
    }
    else
        cout << "Recebido missil nulo em Fase::removerMissil" << endl;

}




void Fase::AdicionarProjetil(sf::Vector2f pos){

    Entidades::Projetil* pProjetil = NULL;
    pProjetil = new Entidades::Projetil(pos, pJogador1, pJogador2);
    if(pProjetil){
        pColisao->incluiProjetil(pProjetil);
        pProjetil->setFase(this);
        Entidade* pEntidade = dynamic_cast<Entidades::Entidade*> (pProjetil);
        if(pEntidade)
            listaMisseis.inserir(pEntidade);
        else
            cout << "erro ao converter Projetil para entidade em Fase::AdicionarProjetil" << endl;
    }
    else
        cout << "erro ao criar Projetil" << endl;


}
void Fase::SalvarFase(std::ofstream* pGravadorFase){

    limparArquivos();
    listaPersonagens.SalvarEntidades();
    listaObstaculos.SalvarEntidades();
    listaMisseis.SalvarEntidades();


}
void Fase::RecuperarFase(){

    pColisao->limpar();
    pJogador1 = NULL;
    pJogador2 = NULL;
    listaPersonagens.esvaziar();
    listaObstaculos.esvaziar();
    listaMisseis.esvaziar();
    RecuperarPersonagens();
    RecuperarObstaculos();
    RecuperarMisseis();



    /*
    while (!pRecuperarFase->eof()){
        int id;
        float posX, posY, tamX, tamY;
        *pRecuperarFase >> id >> posX >> posY >> tamX >> tamY;
        CarregarEntidades(id, sf::Vector2f(posX, posY), sf::Vector2f(tamX, tamY));
    }
    */



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
        pSoldado->setFase(this);
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
void Fase::RecuperarObstaculos(){

    string Atributos;

    ifstream RecuperadorCaixa("Caixa.txt", ios::in);
    if (!RecuperadorCaixa){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Obstaculos::Caixa* pCaixa = NULL;
    while (getline(RecuperadorCaixa, Atributos)){
        pCaixa = new  Entidades::Obstaculos::Caixa(sf::Vector2f(0.0f, 0.0f));
        pCaixa->CarregarSe(Atributos);
            if (pCaixa) {
                pColisao->incluiObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pCaixa));
                listaObstaculos.inserir(static_cast<Entidade*>(pCaixa));
            }
            else
                cout << "Erro ao carregar caixa em Fase::RecuperarObstaculos" << endl;
    }
    RecuperadorCaixa.close();




    ifstream RecuperadorPlataforma("Plataforma.txt", ios::in);
    if (!RecuperadorPlataforma){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Obstaculos::Plataforma* pPlataforma = NULL;
    while (getline(RecuperadorPlataforma, Atributos)){
        pPlataforma = new  Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f, 0.0f));
        pPlataforma->CarregarSe(Atributos);
            if (pPlataforma) {
                pColisao->incluiObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pPlataforma));
                listaObstaculos.inserir(static_cast<Entidade*>(pPlataforma));
            }
            else
                cout << "Erro ao carregar Plataforma em Fase::RecuperarObstaculos" << endl;
    }
    RecuperadorPlataforma.close();


    ifstream RecuperadorEspinhos("Espinhos.txt", ios::in);
    if (!RecuperadorEspinhos){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Obstaculos::Espinhos* pEsp = NULL;
    while (getline(RecuperadorEspinhos, Atributos)){
        pEsp = new  Entidades::Obstaculos::Espinhos(sf::Vector2f(0.0f, 0.0f));
        pEsp->CarregarSe(Atributos);
            if (pEsp) {
                pColisao->incluiObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pEsp));
                listaObstaculos.inserir(static_cast<Entidade*>(pEsp));
            }
            else
                cout << "Erro ao carregar Espinhos em Fase::RecuperarFase" << endl;
    }
    RecuperadorEspinhos.close();

}

void Fase::RecuperarPersonagens(){

    string Atributos;

    ifstream RecuperadorJogador("Jogador.txt", ios::in);
    if (!RecuperadorJogador){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Personagens::Jogador* pJog = NULL;
    while (getline(RecuperadorJogador, Atributos)) {
        pJog = new  Entidades::Personagens::Jogador(sf::Vector2f(0.0f, 0.0f));
        pJog->CarregarSe(Atributos);
            if (pJog) {
                pColisao->setJogador(pJog);
                listaPersonagens.inserir(static_cast<Entidade*>(pJog));
                if(pJogador1 == NULL)
                    pJogador1 = pJog;
                else if(pJogador2 == NULL){
                    pJogador2 = pJog;
                    pJogador2->setJogador2(true);
                }
                else
                    cout << "Erro: Criando mais de dois Jogadores em Fase::RecuperarPersonagens" << endl;
            }
            else
                cout << "Erro ao carregar Jogador em Fase::RecuperarPersonagens" << endl;
    }
    RecuperadorJogador.close();
    Inimigo::setPairpJogadores(pJogador1, pJogador2);


    ifstream RecuperadorCachorro("Cachorro.txt", ios::in);
    if (!RecuperadorCachorro){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Personagens::Cachorro* pCachorro = NULL;
    while (getline(RecuperadorCachorro, Atributos)) {
        pCachorro = new  Entidades::Personagens::Cachorro(sf::Vector2f(0.0f, 0.0f));
        pCachorro->CarregarSe(Atributos);
            if (pCachorro) {
                pColisao->incluiInimigo(static_cast<Entidades::Personagens::Inimigo*>(pCachorro));
                listaPersonagens.inserir(static_cast<Entidade*>(pCachorro));
            }
            else
                cout << "Erro ao carregar Cachorro em Fase::RecuperarPersonagens" << endl;
    }
    RecuperadorCachorro.close();


    ifstream RecuperadorSoldado("Soldado.txt", ios::in);
    if (!RecuperadorSoldado){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Personagens::Soldado* pSoldado = NULL;
    while (getline(RecuperadorSoldado, Atributos)) {
        pSoldado = new  Entidades::Personagens::Soldado(sf::Vector2f(0.0f, 0.0f));
        pSoldado->CarregarSe(Atributos);
            if (pSoldado) {
                pColisao->incluiInimigo(static_cast<Entidades::Personagens::Inimigo*>(pSoldado));
                listaPersonagens.inserir(static_cast<Entidade*>(pSoldado));
                pSoldado->setFase(this);
            }
            else
                cout << "Erro ao carregar Soldado em Fase::RecuperarPersonagens" << endl;
    }
    RecuperadorSoldado.close();


    ifstream RecuperadorLenhador("Lenhador.txt", ios::in);
    if (!RecuperadorLenhador){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Personagens::Lenhador* pLenhador = NULL;
    while (getline(RecuperadorLenhador, Atributos)) {
        pLenhador = new  Entidades::Personagens::Lenhador(sf::Vector2f(0.0f, 0.0f));
        pLenhador->CarregarSe(Atributos);
            if (pLenhador) {
                pColisao->incluiInimigo(static_cast<Entidades::Personagens::Inimigo*>(pLenhador));
                listaPersonagens.inserir(static_cast<Entidade*>(pLenhador));
            }
            else
                cout << "Erro ao carregar Lenhador em Fase::RecuperarPersonagens" << endl;
    }
    RecuperadorLenhador.close();

}

void Fase::RecuperarMisseis(){
    string Atributos;
    ifstream RecuperadorMissil("Missil.txt", ios::in);
    if (!RecuperadorMissil){
        cerr << "Arquivo não pode ser aberto" << endl;
    }
    Entidades::Projetil* pMissil = NULL;
    while (getline(RecuperadorMissil, Atributos)) {
        pMissil = new  Entidades::Projetil(sf::Vector2f(0.0f, 0.0f), pJogador1, pJogador2);
        pMissil->CarregarSe(Atributos);
            if (pMissil) {
                pColisao->incluiProjetil(static_cast<Entidades::Projetil*>(pMissil));
                listaMisseis.inserir(static_cast<Entidade*>(pMissil));
                pMissil->setFase(this);
            }
            else
                cout << "Erro ao carregar Lenhador em Fase::RecuperarPersonagens" << endl;
    }
    RecuperadorMissil.close();



}


void Fase::limparArquivos(){

    /// Limpando os Arquivos
    ofstream Platadorma("Plataforma.txt", std::ios_base::trunc);
    Platadorma.close();
    ofstream Soldado("Soldado.txt", std::ios_base::trunc);
    Soldado.close();
    ofstream Lenhador("Lenhador.txt", std::ios_base::trunc);
    Lenhador.close();
    ofstream Jogador("Jogador.txt", std::ios_base::trunc);
    Jogador.close();
    ofstream Caixa("Caixa.txt", std::ios_base::trunc);
    Caixa.close();
    ofstream Cachorro("Cachorro.txt", std::ios_base::trunc);
    Cachorro.close();
    ofstream Espinhos("Espinhos.txt", std::ios_base::trunc);
    Espinhos.close();
    ofstream Missil("Missil.txt", std::ios_base::trunc);
    Missil.close();


}

