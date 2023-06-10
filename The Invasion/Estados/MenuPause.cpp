#include "MenuPause.h"
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Estados;

MenuPause::MenuPause(): Menu(), Botaovoltar("VOLTAR", font), BotaoSalvar("SALVAR", font){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");

    Botaovoltar.setPosition(495.0f, 390.0f);
    Botaovoltar.setScale(1.5f, 1.5f);
    BotaoSalvar.setPosition(500.0f, 300.0f);
    BotaoSalvar.setScale(1.5f, 1.5f);
}

MenuPause::~MenuPause(){}

void MenuPause::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::V)
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("EstadoJogar");
}

void MenuPause::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));
}

void MenuPause::executar(){
    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    sf::Vector2f fPosMouse((float) posMouse.x, (float) posMouse.y);
    sf::FloatRect corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));

    sf::FloatRect rectVoltar(Botaovoltar.getGlobalBounds());
    if(rectVoltar.intersects(corpoMouse)){
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

    sf::FloatRect rectSalvar(BotaoSalvar.getGlobalBounds());
    if(rectSalvar.intersects(corpoMouse)){
        BotaoSalvar.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(Gerenciadores::GerenciadorEstado::pGEstados)
                Gerenciadores::GerenciadorEstado::pGEstados->salvarFase();
            else
                cout << "pGEstados NULO" << endl;
        }
    }
    else
        BotaoSalvar.setFillColor(sf::Color::White);

    pGrafico->desenharElemento(Botaovoltar);
    pGrafico->desenharElemento(BotaoSalvar);
}