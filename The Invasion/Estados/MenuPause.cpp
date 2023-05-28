#include "MenuPause.h"
using namespace Estados;
#include "../Gerenciadores/GerenciadorEstado.h"

MenuPause::MenuPause(): Estado(), Botaovoltar()
{

    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    Botaovoltar.setString("VOLTAR");
    Botaovoltar.setPosition(600.0f, 400.0f);
    Botaovoltar.setFont(font);
    Botaovoltar.setFillColor(sf::Color::White);
    Botaovoltar.setScale(1.5f, 1.5f);

}
MenuPause::~MenuPause(){

}
void MenuPause::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::V)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("EstadoJogar");
}
void MenuPause::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));

}
void MenuPause::executar(){


    pGrafico->desenharElemento(Botaovoltar);

    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    //cout << "X: " << posMouse.x << "   Y: " << posMouse.y << endl;
    sf::Vector2f fPosMouse((float) posMouse.x, (float) posMouse.y);

    sf::FloatRect rect(Botaovoltar.getGlobalBounds());
    sf::FloatRect corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));
    if(rect.intersects(corpoMouse)){
        Botaovoltar.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(Gerenciadores::GerenciadorEstado::pGEstados)
                Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("EstadoJogar");
            else
                cout << "pGEstados NULO" << endl;
        }
    }
    else
        Botaovoltar.setFillColor(sf::Color::White);


}
