#include "Espinhos.h"
#include "../Personagens/Jogador.h"

using namespace Entidades;
using namespace Obstaculos;

Espinhos::Espinhos(sf::Vector2f pos, sf::Vector2f tam_corpo): Obstaculo(pos, tam_corpo), dano(10) {
    ID = 7;
    corpo.setPosition(pos);
    if(curador){
        dano = 0;
        textura = pGrafico->carregarTextura(ESPINHOS2);
    }
    else
        textura = pGrafico->carregarTextura(ESPINHOS);
    corpo.setTexture(&textura);
}

Espinhos::~Espinhos() {}

void Espinhos::executar() {}

void Espinhos::obstar(Entidades::Personagens::Jogador* pJog, sf::Vector2f DistExtremidades, bool colidiu_X){
    /// empurra o Jogador para fora de si devagar e o da dano a cada 5 seguundos após entrar e se espinho for curador ele não faz nada
    if(pJog){
        if(clockInteracao.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - dano);
            clockInteracao.restart();
        }
        if (!colidiu_X) {
            if (pJog->getPosition().y < getPosition().y){
                pJog->mover(0.0f, DistExtremidades.y / 100);
                pJog->setSuspensoNoAR(false);
            }
            else{
                pJog->mover(0.0f, -DistExtremidades.y / 100);
                if(pJog->getVelocidade().y < 0.0f)
                    pJog->setVelocidade_y(0.0f);
            }

        }
        else {
            if (pJog->getPosition().x < getPosition().x)
                pJog->mover(DistExtremidades.x / 100, 0.0f);
            else
                pJog->mover(-DistExtremidades.x  / 100, 0.0f);
        }
    }
    else
        cout << "pJog nulo em obstar dos Espinhos" << endl;
}

void Espinhos::obstar(Entidades::Personagens::Inimigo* pInimigo, sf::Vector2f DistExtremidades, bool colidiu_X){}

void Espinhos::obstar(Entidades::Obstaculos::Obstaculo* pObs, sf::Vector2f DistExtremidades, bool colidiu_X){}

void Espinhos::salvar(){
    ofstream GravadorEspinhos("Espinhos.txt", ios_base::app);
    if (GravadorEspinhos.is_open()) {
        GravadorEspinhos << getPosition().x << ' ' << getPosition().y << ' ' << curador << ' ' << dano <<  endl;
        GravadorEspinhos.close();
    }
    else
        cout << "Erro ao abrir o arquivo." << std::endl;
}

void Espinhos::CarregarSe(string atributos){
    std::istringstream iss(atributos);
    float posX, posY;
    iss >>  posX >> posY >> curador >> dano;
    if (!iss.fail()) {
        setPosition(sf::Vector2f(posX, posY));
    }
    else
        cout << "Erro ao converter os valores em CarregarSe" << endl;

    if(curador){
        dano = 0;
        textura = pGrafico->carregarTextura(ESPINHOS2);
    }
    else
        textura = pGrafico->carregarTextura(ESPINHOS);
}