#include "Soldado.h"
#include "../../Fases/Fase.h"
using namespace Entidades;
using namespace Personagens;

Soldado::Soldado(sf::Vector2f pos, Fases::Fase* pFaseAux, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), dano(5), pFase(pFaseAux),
 raioTiroMAX(1100.0f), raioTiroMIN(200.0f){
    ID = 4;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(SOLDADO);
    corpo.setTexture(&textura);
    relogioAtirar.restart();
}

Soldado::~Soldado() {}

void Soldado::executar(){
    if (pJogadores.first || pJogadores.second) {
        sf::Vector2f posJog, posSold = getPosition();
        if(pJogadores.first && pJogadores.second){
            if(pJogadores.first->getPosition().x - getPosition().x < pJogadores.second->getPosition().x - getPosition().x)
                posJog = pJogadores.first->getPosition();
            else
                posJog = pJogadores.second->getPosition();
        }
        else if(pJogadores.first)
            posJog = pJogadores.first->getPosition();
        else
            posJog = pJogadores.second->getPosition();

        float Dist(sqrt((posJog.x - posSold.x) * (posJog.x - posSold.x) + (posJog.y - posSold.y) * (posJog.y - posSold.y)));
        if(Dist > 700.0f)
            moveAleatorio();
        else
            Afastar_se();

        if (Dist > raioTiroMIN && Dist < raioTiroMAX)
            Atirar();

    }
    else
        cout << "pair_pJogadores NULOS em soldado" << endl;

    efeitoGravidade();
}

void Soldado::Afastar_se(){
    if(pJogadores.first || pJogadores.second){
        Jogador* pJogador;
        if(pJogadores.first && pJogadores.second){
            if(pJogadores.first->getPosition().x - getPosition().x < pJogadores.second->getPosition().x - getPosition().x)
                pJogador = pJogadores.first;
            else
                pJogador = pJogadores.second;
        }
        else if(pJogadores.first)
            pJogador = pJogadores.first;
        else
            pJogador = pJogadores.second;
        float DistX(pJogador->getPosition().x - getPosition().x);
        if(DistX > 0.0f)
            mover(-vel.x, 0.0f);
        else
            mover(vel.x, 0.0f);
    }
    else
        cout << "pJogadors NULOS em soldado" << endl;
}

void Soldado::Atirar(){
    if(pJogadores.first || pJogadores.second){
        if(pFase){
            if(relogioAtirar.getElapsedTime().asSeconds() > 8.0f){
                cout << "Atirou" << endl;
                pFase->AdicionarProjetil(sf::Vector2f(getPosition().x + corpo.getSize().x, getPosition().y + corpo.getSize().y/2));
                relogioAtirar.restart();
            }
        }
		else
			cout << "pFase NULO em Atirar do soldado" << endl;

    }
    else
        cout << "pJogadors NULOS em Atirar do soldado" << endl;
}

void Soldado::danar(Jogador* pJog) {
    if (pJog) {
        if(clockInteracao.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - dano);
            clockInteracao.restart();
        }
    }
}

void Soldado::setFase(Fases::Fase* pFaseAux){
    if(pFaseAux)
        pFase = pFaseAux;
    else
        cout << "Passadp pFase nulo em setFase do soldado" << endl;
}

void Soldado::salvar(){
    ofstream GravadorSoldado("data/Soldado.txt", ios_base::app);
    if (GravadorSoldado.is_open()) {
        GravadorSoldado << getPosition().x << ' ' << getPosition().y << ' ' << vida << ' ' << dano <<  endl;
        GravadorSoldado.close();
    }
    else
        cout << "Erro ao abrir o arquivo." << endl;
}

void Soldado::CarregarSe(string atributos){
    std::istringstream iss(atributos);
    float posX, posY;
    iss >>  posX >> posY >> vida >> dano;
    if (!iss.fail()) {
        setPosition(sf::Vector2f(posX, posY));
    }
    else
        cout << "Erro ao converter os valores em CarregarSe" << endl;
}
