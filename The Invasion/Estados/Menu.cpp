#include "Menu.h"
using namespace Estados;
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Gerenciadores;

Menu::Menu(): font(),  pGrafico(pGrafico->getGerenciadorGrafico()), executando(false) {
	if (!font.loadFromFile("The invasion/assets/fonts/PlayfairDisplay-Regular.ttf"))
        cout << "ERRO AO CARREGAR FONTE" << endl;
}
Menu::~Menu(){

}
void Menu::setExecutando(bool ativo){
    executando = ativo;
}

void Menu::guardarPontuacao(int num) {

}

void Menu::carregarFase2() {

}