#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar() {

}
EstadoJogar::~EstadoJogar(){

}
void EstadoJogar::executar(){
    fase1.executar();
}
void EstadoJogar::PrimeiroExecutar(){
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
}
void EstadoJogar::TeclaPressionada(const sf::Keyboard::Key tecla){
    fase1.TeclaPressionada(tecla);
}
