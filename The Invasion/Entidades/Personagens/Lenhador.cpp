#include "Lenhador.h"
using namespace Entidades;
using namespace Personagens;

Lenhador::Lenhador(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), forca(18){
    ID = 2;
    corpo.setPosition(pos);
    textura = pGrafico->carregarTextura(LENHADOR);
    corpo.setTexture(&textura);
}

Lenhador::~Lenhador() {


}

void Lenhador::danar(Jogador* pJog) {
    if (pJog) {
        if(clockInteracao.getElapsedTime().asSeconds() > 5.0f){
            pJog->setVida(pJog->getVida() - forca);
            clockInteracao.restart();
        }
    }
}
void Lenhador::salvar(){
    ofstream GravadorLenhador("Lenhador.txt", ios_base::app);
    if (GravadorLenhador.is_open()) {
        GravadorLenhador << getPosition().x << ' ' << getPosition().y << ' '  << forca <<  endl;
        GravadorLenhador.close();
    }
    else
        cout << "Erro ao abrir o arquivo." << std::endl;
}

