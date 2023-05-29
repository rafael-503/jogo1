#include "Estado.h"
using namespace Estados;
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Gerenciadores;

Estado::Estado(): font(),  pGrafico(pGrafico->getGerenciadorGrafico()), executando(false) {
	if (!font.loadFromFile("The invasion/assets/fonts/PlayfairDisplay-Regular.ttf"))
        cout << "ERRO AO CARREGAR FONTE" << endl;
}
Estado::~Estado(){

}
void Estado::setExecutando(bool ativo){
    executando = ativo;
}

void Estado::guardarPontuacao(int num) {

}
