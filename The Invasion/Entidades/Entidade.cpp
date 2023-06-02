#include "../stdafx.h"
#include "Entidade.h"
using namespace Entidades;
#include "../Gerenciadores/GerenciadorEstado.h"

Entidade::Entidade(sf::Vector2f tam_corpo) :
    Ente(), corpo(tam_corpo), vel(0.0f, 0.0f), SuspensoNoAR(true), vida(100), pontuacao(0){
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

string Entidade::getTipo() {
    return Tipo;
}

void Entidade::setVelocidade(sf::Vector2f v) {
    vel = v;
}

sf::Vector2f Entidades::Entidade::getVelocidade() const {
    return vel;
}

float Entidade::getMassa() const{
    return massa;
}

void Entidade::setMassa(float Massa){
    massa = Massa;
}
void Entidade::efeitoGravidade(){

    if(SuspensoNoAR && Gerenciadores::GerenciadorEstado::pGEstados->getStringEstadoAtual() == "EstadoJogar"){
        //cout << "GRAVIDADE" << endl;
        float G = 0.5f;
        //float dt = relogio.getElapsedTime().asSeconds();
        vel.y = vel.y + G;
        corpo.move(0.0f, vel.y);
    }
    else if (vel.y > 0)
        vel.y = 0;

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

void Entidade::setPontuacao(int pontuacao) {
	this->pontuacao = pontuacao;
}

int Entidade::getPontuacao() const {
	return pontuacao;
}
void Entidade::setSuspensoNoAR(bool aux){
    SuspensoNoAR = aux;

}
void Entidade::mover(float moveX, float moveY){
    corpo.move(moveX, moveY);
}
void Entidade::setVelocidade_y(float aux){
    vel.y = aux;
}
