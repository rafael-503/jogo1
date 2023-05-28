#include "../stdafx.h"
#include "Entidade.h"
using namespace Entidades;


Entidade::Entidade(sf::Vector2f tam_corpo) :
    Ente(), corpo(tam_corpo), vel(0.0f, 0.0f), SuspensoNoAR(true), vida(100){
}

Entidade::~Entidade() {}

sf::RectangleShape Entidade::getCorpo() {
    return corpo;
}

const sf::Vector2f Entidade::getPosition() const {
    return corpo.getPosition();
}
const sf::Vector2f Entidade::getSize() const {
    return corpo.getSize();

}
void Entidade::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {


}
string Entidade::getTipo() {
    return Tipo;
}

void Entidade::setVelocidade(sf::Vector2f v) {
    vel = v;
}
float Entidade::getMassa() const{
    return massa;
}

void Entidade::setMassa(float Massa){
    massa = Massa;
}
void Entidade::efeitoGravidade(){

    if(SuspensoNoAR){
        //cout << "GRAVIDADE" << endl;
        float G = 1.0f;
        float dt = relogio.getElapsedTime().asSeconds();
        vel.y = vel.y + dt*G;
        corpo.move(0.0f, vel.y);
    }
    else
        relogio.restart();

    SuspensoNoAR = true;

}

void Entidade::setVida(int vida) {
	this->vida = vida;
    if(getVida() < 0)
		setVida(0);
}

int Entidade::getVida() const {
	return vida;
}