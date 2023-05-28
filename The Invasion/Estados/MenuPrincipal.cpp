#include "../Gerenciadores/GerenciadorEstado.h"
#include "MenuPrincipal.h"
using namespace Estados;



MenuPrincipal::MenuPrincipal(): TextoJogar(), font(), pGrafico(pGrafico->getGerenciadorGrafico())
{
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
	if (!font.loadFromFile("The invasion/assets/fonts/PlayfairDisplay-Regular.ttf"))
        cout << "ERRO AO CARREGAR FONTE" << endl;
    TextoJogar.setString("JOGAR");
    TextoJogar.setPosition(550.0f, 400.0f);
    TextoJogar.setFont(font);
    TextoJogar.setFillColor(sf::Color::White);
    TextoJogar.setScale(1.5f, 1.5f);

}
MenuPrincipal::~MenuPrincipal(){

}

void MenuPrincipal::executar(){

    pGrafico->desenharElemento(TextoJogar);

    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    //cout << "X: " << posMouse.x << "   Y: " << posMouse.y << endl;
    sf::Vector2f fPosMouse((float) posMouse.x, (float) posMouse.y);

    sf::FloatRect rect(TextoJogar.getGlobalBounds());
    sf::FloatRect corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));
    if(rect.intersects(corpoMouse)){
        TextoJogar.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(Gerenciadores::GerenciadorEstado::pGEstados)
                Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("EstadoJogar");
            else
                cout << "pGEstados NULO" << endl;
        }
    }
    else
        TextoJogar.setFillColor(sf::Color::White);


}
void MenuPrincipal::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));

}
void MenuPrincipal::TeclaPressionada(const sf::Keyboard::Key tecla){

}

